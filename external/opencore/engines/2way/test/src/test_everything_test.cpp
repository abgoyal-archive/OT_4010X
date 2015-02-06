
#include "test_everything_test.h"

void test_everything_test::test()
{
    int error = 0;
    char *filename = new char[iFilename.get_size() + 1];
    if ((filename == NULL) || (oscl_UnicodeToUTF8(iFilename.get_cstr(), iFilename.get_size(), filename, iFilename.get_size() + 1) == 0))
    {
        OSCL_LEAVE(-1);
    }

    fprintf(fileoutput, "Start test everything test, proxy %d, file %s\n", iUseProxy, filename);

    delete filename;

    scheduler = OsclExecScheduler::Current();

    this->AddToScheduler();

    if (start_async_test())
    {
        OSCL_TRY(error, scheduler->StartScheduler());
        if (error != 0)
        {
            OSCL_LEAVE(error);
        }
    }

    destroy_sink_source();

    this->RemoveFromScheduler();
}


void test_everything_test::Run()
{
    if (terminal)
    {
        if (iUseProxy)
        {
            CPV2WayProxyFactory::DeleteTerminal(terminal);
        }
        else
        {
            CPV2WayEngineFactory::DeleteTerminal(terminal);
        }
        terminal = NULL;
    }

    scheduler->StopScheduler();
}

void test_everything_test::DoCancel()
{
}

void test_everything_test::HandleInformationalEventL(const CPVCmnAsyncInfoEvent& aEvent)
{
    int error = 0;

    switch (aEvent.GetEventType())
    {
        case PVT_INDICATION_INCOMING_TRACK:
            TPVChannelId id;

            if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_VIDEO)
            {
                OSCL_TRY(error, iVideoAddSinkId = terminal->AddDataSinkL(*iVideoSink, id));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }
            }

            if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_AUDIO)
            {
                OSCL_TRY(error, iAudioAddSinkId = terminal->AddDataSinkL(*iAudioSink, id));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }
            }
            break;

        case PVT_INDICATION_DISCONNECT:
            iAudioSourceAdded = false;
            iVideoSourceAdded = false;
            iAudioSinkAdded = false;
            iVideoSinkAdded = false;
            break;

        case PVT_INDICATION_CLOSE_TRACK:
            if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_VIDEO)
            {
                if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[1] == INCOMING)
                {
                    iVideoSinkAdded = false;
                }
                else
                {
                    iVideoSourceAdded = false;
                }
            }
            else if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[0] == PV_AUDIO)
            {
                if (((CPVCmnAsyncEvent&)aEvent).GetLocalBuffer()[1] == INCOMING)
                {
                    iAudioSinkAdded = false;
                }
                else
                {
                    iAudioSourceAdded = false;
                }
            }
            break;

        case PVT_INDICATION_INTERNAL_ERROR:
            break;

        default:
            break;
    }
}

void test_everything_test::CommandCompletedL(const CPVCmnCmdResp& aResponse)
{
    int error = 0;
    switch (aResponse.GetCmdType())
    {
        case PVT_COMMAND_INIT:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_wHeapString<OsclMemAllocator> filename(RECORDED_CALL_FILENAME);
                OSCL_TRY(error, terminal->InitRecordFileL(filename));
                if (error)
                {
                    test_is_true(false);
                    reset();
                    break;
                }

                OSCL_TRY(error, terminal->InitPlayFileL(iFilename));
                if (error)
                {
                    test_is_true(false);
                    reset();
                    break;
                }

                OSCL_TRY(error, terminal->ConnectL(iConnectOptions));
                if (error)
                {
                    test_is_true(false);
                    reset();
                }
            }
            else
            {
                test_is_true(false);
                RunIfNotReady();
            }
            break;

        case PVT_COMMAND_RESET:
            RunIfNotReady();
            break;

        case PVT_COMMAND_ADD_DATA_SOURCE:
            if (aResponse.GetCmdId() == iAudioAddSourceId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iAudioSourceAdded = true;

                    if (check_audio_started() && iRecordFileInitialized)
                    {
                        OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioAddSourceId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoAddSourceId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iVideoSourceAdded = true;

                    if (check_video_started())
                    {
                        OSCL_TRY(error, terminal->AddPreviewSinkL(*iVideoSource, *iVideoPreview));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }

                        if (iRecordFileInitialized)
                        {
                            OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                            if (error)
                            {
                                test_is_true(false);
                                disconnect();
                            }
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoAddSourceId = 0;
            }
            break;

        case PVT_COMMAND_REMOVE_DATA_SOURCE:
            if (aResponse.GetCmdId() == iAudioRemoveSourceId)
            {
                iAudioRemoveSourceId = 0;
                iAudioSourceAdded = false;
            }
            else if (aResponse.GetCmdId() == iVideoRemoveSourceId)
            {
                iVideoRemoveSourceId = 0;
                iVideoSourceAdded = false;
            }
            break;

        case PVT_COMMAND_ADD_DATA_SINK:
            if (aResponse.GetCmdId() == iAudioAddSinkId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iAudioSinkAdded = true;

                    if (check_audio_started() && iRecordFileInitialized)
                    {
                        OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioAddSinkId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoAddSinkId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iVideoSinkAdded = true;

                    if (check_video_started())
                    {
                        OSCL_TRY(error, terminal->AddPreviewSinkL(*iVideoSource, *iVideoPreview));
                        if (error)
                        {
                            test_is_true(false);
                            disconnect();
                        }

                        if (iRecordFileInitialized)
                        {
                            OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                            if (error)
                            {
                                test_is_true(false);
                                disconnect();
                            }
                        }
                    }
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoAddSinkId = 0;
            }
            break;

        case PVT_COMMAND_REMOVE_DATA_SINK:
            if (aResponse.GetCmdId() == iAudioRemoveSinkId)
            {
                iAudioRemoveSinkId = 0;
                iAudioSinkAdded = false;
            }
            else if (aResponse.GetCmdId() == iVideoRemoveSinkId)
            {
                iVideoRemoveSinkId  = 0;
                iVideoSinkAdded = false;
            }
            break;

        case PVT_COMMAND_CONNECT:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, iAudioAddSourceId = terminal->AddDataSourceL(*iAudioSource));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }

                OSCL_TRY(error, iVideoAddSourceId = terminal->AddDataSourceL(*iVideoSource));
                if (error)
                {
                    test_is_true(false);
                    disconnect();
                }
            }
            else
            {
                test_is_true(false);
                reset();
            }
            break;

        case PVT_COMMAND_DISCONNECT:
            iAudioSourceAdded = false;
            iVideoSourceAdded = false;
            iAudioSinkAdded = false;
            iVideoSinkAdded = false;

            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                test_is_true(true);
            }

            OSCL_TRY(error, terminal->ResetL());
            if (error)
            {
                test_is_true(false);
                RunIfNotReady();
            }
            break;

        case PVT_COMMAND_INIT_RECORD_FILE:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                iRecordFileInitialized = true;

                if (check_audio_started())
                {
                    OSCL_TRY(error, iAudioStartRecId = terminal->StartRecordL(*iAudioSink));
                    if (error)
                    {
                        test_is_true(false);
                        disconnect();
                    }
                }

                if (check_video_started())
                {
                    OSCL_TRY(error, iVideoStartRecId = terminal->StartRecordL(*iVideoSink));
                    if (error)
                    {
                        test_is_true(false);
                        disconnect();
                    }
                }
            }
            else
            {
                test_is_true(false);
                reset();
            }
            break;

        case PVT_COMMAND_START_RECORD:
            if (aResponse.GetCmdId() == iAudioStartRecId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iAudioRecStarted = true;
                    is_test_done();
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iAudioStartRecId = 0;
            }
            else if (aResponse.GetCmdId() == iVideoStartRecId)
            {
                if (aResponse.GetCmdStatus() == PVMFSuccess)
                {
                    iVideoRecStarted = true;
                    is_test_done();
                }
                else
                {
                    test_is_true(false);
                    disconnect();
                }
                iVideoStartRecId = 0;
            }
            break;

        case PVT_COMMAND_ADD_PREVIEW_SINK:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                iVideoPreviewStarted = true;
                is_test_done();
            }
            else
            {
                test_is_true(false);
                disconnect();
            }
            break;

        case PVT_COMMAND_INIT_PLAY_FILE:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, terminal->UsePlayFileAsSourceL(true));
                if (error)
                {
                    test_is_true(false);
                }
            }
            else
            {
                test_is_true(false);
            }
            break;

        case PVT_COMMAND_USE_PLAY_FILE:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, terminal->StartPlayL());
                if (error)
                {
                    test_is_true(false);
                }
            }
            else
            {
                test_is_true(false);
            }
            break;

        case PVT_COMMAND_START_PLAY:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                iPlayStarted = true;
                is_test_done();
            }
            else
            {
                test_is_true(false);
            }
            break;
    }
}

bool test_everything_test::start_async_test()
{
    int error = 0;

    if (iUseProxy)
    {
        OSCL_TRY(error, terminal = CPV2WayProxyFactory::CreateTerminalL(PV_324M,
                                   (MPVCmnCmdStatusObserver *) this,
                                   (MPVCmnInfoEventObserver *) this,
                                   (MPVCmnErrorEventObserver *) this));
    }
    else
    {
        OSCL_TRY(error, terminal = CPV2WayEngineFactory::CreateTerminalL(PV_324M,
                                   (MPVCmnCmdStatusObserver *) this,
                                   (MPVCmnInfoEventObserver *) this,
                                   (MPVCmnErrorEventObserver *) this));
    }

    if (error)
    {
        test_is_true(false);
        return false;
    }

    create_sink_source();

    OSCL_TRY(error, terminal->InitL(iSdkInitInfo, iCommServer));
    if (error)
    {
        test_is_true(false);

        if (iUseProxy)
        {
            CPV2WayProxyFactory::DeleteTerminal(terminal);
        }
        else
        {
            CPV2WayEngineFactory::DeleteTerminal(terminal);
        }

        terminal = NULL;
        return false;
    }

    return true;
}

void test_everything_test::is_test_done()
{
    if (check_rec_started() &&
            iPlayStarted &&
            iVideoPreviewStarted)
    {
        disconnect();
    }
}


