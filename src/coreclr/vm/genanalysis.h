// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

// #define GEN_ANALYSIS_STRESS

#ifndef __GENANALYSIS_H__
#define __GENANALYSIS_H__

#ifdef FEATURE_PERFTRACING
#include "eventpipeadaptertypes.h"
#else
typedef struct _EventPipeSession EventPipeSession;
#endif // FEATURE_PERFTRACING

enum GcGenAnalysisState
{
    Uninitialized = 0,
    Enabled = 1,
    Disabled = 2,
    Done = 3,
};

#define GENAWARE_TRACE_FILE_NAME W("gcgenaware.{pid}.nettrace")
#define GENAWARE_DUMP_FILE_NAME W("gcgenaware.{pid}.dmp")
#define GENAWARE_COMPLETION_FILE_NAME W("gcgenaware.{pid}.nettrace.completed")

extern bool s_forcedGCInProgress;
extern GcGenAnalysisState gcGenAnalysisState;
extern EventPipeSession* gcGenAnalysisEventPipeSession;
extern uint64_t gcGenAnalysisEventPipeSessionId;
extern GcGenAnalysisState gcGenAnalysisConfigured;
extern int64_t gcGenAnalysisGen;
extern uint64_t gcGenAnalysisBytes;
extern uint64_t gcGenAnalysisTime;
extern int64_t gcGenAnalysisIndex;
extern bool gcGenAnalysisTrace;
extern bool gcGenAnalysisDump;

class GenAnalysis
{
public:
    static void Initialize();
    static void EnableGenerationalAwareSession();
};

#endif 
