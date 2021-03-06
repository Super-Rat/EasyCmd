﻿#include "EditorFactory.h"
#include "PingCmdEditor.h"
#include "NetStatCmdEditor.h"
#include "SystemToolEditor.h"
#include "LauncherEditor.h"
#include "IpconfigEditor.h"
#include "TasklistEditor.h"
#include "TaskkillEditor.h"
#include "TracertCmdEditor.h"
#include "CdCmdEditor.h"

ICmdEditor *newPingCmdEditor() { return new PingCmdEditor; }
ICmdEditor *newNetStatCmdEditor() { return new NetStatCmdEditor; }
ICmdEditor *newSystemToolsEditor() { return new SystemToolEditor; }
ICmdEditor *newLauncherEditor() { return new LauncherEditor; }
ICmdEditor *newIpconfigEditor() { return new IpconfigEditor; }
ICmdEditor *newTasklistEditor() { return new TasklistEditor; }
ICmdEditor *newTaskkillEditor() { return new TaskkillEditor; }
ICmdEditor *newTracertCmdEditor() { return new TracertCmdEditor; }
ICmdEditor *newCdCmdEditor() { return new CdCmdEditor; }

EditorFactory::EditorFactory()
{
    m_editor_map.clear();

    // 关键字小写
    m_editor_map.insert("ping", newPingCmdEditor);
    m_editor_map.insert("netstat", newNetStatCmdEditor);
    m_editor_map.insert("systemTools", newSystemToolsEditor);
    m_editor_map.insert("launcher", newLauncherEditor);
    m_editor_map.insert("ipconfig", newIpconfigEditor);
    m_editor_map.insert("tasklist", newTasklistEditor);
    m_editor_map.insert("taskkill", newTaskkillEditor);
    m_editor_map.insert("tracert", newTracertCmdEditor);
    m_editor_map.insert("cd", newCdCmdEditor);
}

ICmdEditor *EditorFactory::createEditor(const QString &name)
{
    ICmdEditor *editor = NULL;
    newEditorFunc func = m_editor_map.value(name);
    if (func) editor = func();
    return editor;
}
