//----------------------------------------------------------------------------
//
// cfgExdiGdbSrvHelper.h
//
// Helper for reading the Exdi-GdbServer configuration file.
//
// Copyright (c) Microsoft. All rights reserved.
//----------------------------------------------------------------------------
#pragma once
#ifndef CFGEXDIGDBSRVHELPER_H
#define CFGEXDIGDBSRVHELPER_H
#include <atlbase.h> 
#include <string>
#include <memory>
#include <vector>
#include "GdbSrvControllerLib.h"

using namespace std;
using namespace GdbSrvControllerLib;

//=============================================================================
// Public defines and typedefs
//=============================================================================

class ConfigExdiGdbServerHelper final
{
    public:
        static ConfigExdiGdbServerHelper & GetInstanceCfgExdiGdbServer(_In_opt_ PCWSTR pXmlConfigFile);
        TargetArchitecture GetTargetArchitecture();
        DWORD GetTargetFamily();
        bool GetDisplayCommPacketsCharacters();
        bool GetDebuggerSessionByCore();
        bool GetIntelSseContext();
        DWORD64 GetHeuristicScanMemorySize();
        void GetExdiComponentUuid(_Out_ wstring & uuid);
        unsigned GetNumberOfCores();
        bool GetMultiCoreGdbServer();
        size_t GetMaxServerPacketLength();
        int GetMaxConnectAttempts();
        int GetSendPacketTimeout();
        int GetReceiveTimeout();
        void GetGdbServerConnectionParameters(_Out_ vector<wstring> & coreConnections);
        void GetExdiComponentAgentNamePacket(_Out_ wstring & agentName);
        void GetRequestQSupportedPacket(_Out_ wstring& requestPacket);
        bool IsExceptionThrowEnabled();
        TargetArchitecture GetGdbServerRegisterArchitecture();
        void GetGdbServerTargetName(_Out_ wstring& agentName);
        void GetTargetDescriptionFileName(_Out_ wstring & fileName);
        bool IsSupportedSpecialMemoryCommand();
        bool IsSupportedPhysicalMemoryCommand();
        bool IsSupportedSupervisorMemoryCommand();
        bool IsSupportedHypervisorMemoryCommand();
        bool IsSupportedSpecialMemoryRegister();
        bool IsSupportedSystemRegistersGdbMonitor();
        bool IsSupportedSystemRegisterDecoding();
        void SetXmlBufferToParse(_In_ PCWSTR pXmlConfigFile);
        bool ReadConfigFile(_In_ PCWSTR pXmlConfigFile);
        void GetRegisterGroupFile(_In_ RegisterGroupType fileType, _Out_ wstring & fileName);
        TargetArchitecture GetRegisterGroupArchitecture();
        bool IsSystemRegistersAvailable();
        bool IsRegisterGroupFileAvailable();
        void GetGdbServerRegisters(_Out_ unique_ptr<vector<RegistersStruct>> * spRegisters);
        void GetGdbServerSystemRegisters(_Out_ unique_ptr<vector<RegistersStruct>> * spSystemRegisters);
        void GetSystemRegistersMapAccessCode(_Out_ unique_ptr<systemRegistersMapType> * spMapSystemRegs);

    private:
        ConfigExdiGdbServerHelper(_In_opt_ PCWSTR pXmlConfigFile);
        ~ConfigExdiGdbServerHelper();
        class ConfigExdiGdbServerHelperImpl;
        std::unique_ptr <ConfigExdiGdbServerHelperImpl> m_pConfigExdiGdbServerHelperImpl;
};

#endif // CFGEXDIGDBSRVHELPER
