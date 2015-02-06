
#include "init_play_reset_test.h"



void init_play_reset_test::test()
{
    int error = 0;
    char *filename = new char[iFilename.get_size() + 1];
    if ((filename == NULL) || (oscl_UnicodeToUTF8(iFilename.get_cstr(), iFilename.get_size(), filename, iFilename.get_size() + 1) == 0))
    {
        OSCL_LEAVE(-1);
    }

    fprintf(fileoutput, "Start init play reset test, proxy %d, file %s\n", iUseProxy, filename);

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


void init_play_reset_test::Run()
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

void init_play_reset_test::DoCancel()
{
}


void init_play_reset_test::HandleInformationalEventL(const CPVCmnAsyncInfoEvent& aEvent)
{
}

void init_play_reset_test::CommandCompletedL(const CPVCmnCmdResp& aResponse)
{
    int error = 0;
    switch (aResponse.GetCmdType())
    {
        case PVT_COMMAND_INIT:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, terminal->InitPlayFileL(iFilename));
                if (error)
                {
                    test_is_true(false);
                    reset();
                }
                else
                {

                }
            }
            else
            {
                test_is_true(false);
                reset();
            }
            break;

        case PVT_COMMAND_RESET:
            RunIfNotReady();
            break;

        case PVT_COMMAND_INIT_PLAY_FILE:
            if (aResponse.GetCmdStatus() == PVMFSuccess)
            {
                OSCL_TRY(error, terminal->ResetL());
                if (error)
                {
                    test_is_true(false);
                    RunIfNotReady();
                }
                else
                {
                    test_is_true(true);
                }
            }
            else
            {
                test_is_true(false);
                RunIfNotReady();
            }
            break;
    }
}

bool init_play_reset_test::start_async_test()
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





