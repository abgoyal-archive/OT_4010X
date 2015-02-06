
#ifndef PVMF_JITTER_BUFFER_COMMON_INTERNAL_H
#define PVMF_JITTER_BUFFER_COMMON_INTERNAL_H

//Logging macros
#if 0
#define PVMF_JB_LOGERROR(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipLogger,PVLOGMSG_ERR,m);
#define PVMF_JB_LOGWARNING(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipLogger,PVLOGMSG_WARNING,m);
#define PVMF_JB_LOGINFOHI(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_HLDBG,ipLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGINFOMED(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_MLDBG,ipLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGINFOLOW(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_LLDBG,ipLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGINFO(m) PVMF_JB_LOGINFOMED(m)
#define PVMF_JB_LOGDATATRAFFIC(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGDATATRAFFIC_IN(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerIn,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGDATATRAFFIC_IN_E(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerIn,PVLOGMSG_ERR,m);
#define PVMF_JB_LOGDATATRAFFIC_OUT(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerOut,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGDATATRAFFIC_OUT_E(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerOut,PVLOGMSG_ERR,m);
#define PVMF_JB_LOGCLOCK(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipClockLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGMAXRTPTS(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipMaxRTPTsLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGCLOCK_SESSION_DURATION(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipClockLoggerSessionDuration,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGCLOCK_REBUFF(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipClockLoggerRebuff,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGDIAGNOSTICS(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_PROF,ipDiagnosticsLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGDATATRAFFIC_FLOWCTRL(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerFlowCtrl,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGDATATRAFFIC_FLOWCTRL_E(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerFlowCtrl,PVLOGMSG_ERR,m);

#define PVMF_JB_LOG_RTCP(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipRTCPLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOG_RTCP_ERR(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipRTCPLogger,PVLOGMSG_ERR,m);
#define PVMF_JB_LOG_RTCPDATATRAFFIC_IN(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipRTCPDataPathLoggerIn,PVLOGMSG_INFO,m);
#define PVMF_JB_LOG_RTCPDATATRAFFIC_OUT(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipRTCPDataPathLoggerOut,PVLOGMSG_INFO,m);
#define PVMF_JB_LOG_RTCPDATATRAFFIC_IN_E(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipRTCPDataPathLoggerIn,PVLOGMSG_ERR,m);

#define PVMF_JB_LOG_FW(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipDataPathLoggerFireWall,PVLOGMSG_INFO,m);
#define PVMF_JB_LOG_EVENTS_CLOCK(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_MLDBG,ipJBEventsClockLogger ,PVLOGMSG_INFO,m);
#define PVMF_JB_LOG_RTCP_AVSYNC(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipRTCPAVSyncLogger,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGCLOCK_SESSION_DURATION(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipClockLoggerSessionDuration,PVLOGMSG_INFO,m);
#define PVMF_JB_LOGEVENTNOTIFIER(m) PVLOGGER_LOGMSG(PVLOGMSG_INST_REL,ipLogger,PVLOGMSG_INFO,m);
#else
#define PVMF_JB_LOGERROR(m) NULL;
#define PVMF_JB_LOGWARNING(m) NULL;
#define PVMF_JB_LOGINFOHI(m) NULL;
#define PVMF_JB_LOGINFOMED(m) NULL;
#define PVMF_JB_LOGINFOLOW(m) NULL;
#define PVMF_JB_LOGINFO(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC_IN(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC_IN_E(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC_OUT(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC_OUT_E(m) NULL;
#define PVMF_JB_LOGCLOCK(m) NULL;
#define PVMF_JB_LOGMAXRTPTS(m) NULL;
#define PVMF_JB_LOGCLOCK_SESSION_DURATION(m) NULL;
#define PVMF_JB_LOGCLOCK_REBUFF(m) NULL;
#define PVMF_JB_LOGDIAGNOSTICS(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC_FLOWCTRL(m) NULL;
#define PVMF_JB_LOGDATATRAFFIC_FLOWCTRL_E(m) NULL;
#define PVMF_JB_LOG_RTCP(m) NULL;
#define PVMF_JB_LOG_RTCP_ERR(m) NULL;
#define PVMF_JB_LOG_RTCPDATATRAFFIC_IN(m) NULL;
#define PVMF_JB_LOG_RTCPDATATRAFFIC_OUT(m) NULL;
#define PVMF_JB_LOG_RTCPDATATRAFFIC_IN_E(m) NULL;
#define PVMF_JB_LOG_FW(m) NULL;
#define PVMF_JB_LOG_EVENTS_CLOCK(m) NULL;
#define PVMF_JB_LOG_RTCP_AVSYNC(m) NULL;
#define PVMF_JB_LOGCLOCK_SESSION_DURATION(m) NULL;
#define PVMF_JB_LOGEVENTNOTIFIER(m) NULL;
#endif

#if (PVLOGGER_INST_LEVEL > PVLOGMSG_INST_LLDBG)
#define LOGCLIENTANDESTIMATEDSERVCLK_DATAPATH LogClientAndEstimatedServerClock(ipDataPathLoggerIn)
#define LOGCLIENTANDESTIMATEDSERVCLK_DATAPATH_OUT LogClientAndEstimatedServerClock(ipDataPathLoggerOut)
#define LOGCLIENTANDESTIMATEDSERVCLK_REBUFF LogClientAndEstimatedServerClock(ipClockLoggerRebuff)
#else
#define LOGCLIENTANDESTIMATEDSERVCLK_DATAPATH
#define LOGCLIENTANDESTIMATEDSERVCLK_REBUFF
#define LOGCLIENTANDESTIMATEDSERVCLK_DATAPATH_OUT
#endif

#endif
