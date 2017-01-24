
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Werk/Commands/CommandManager.hpp"
#include "Werk/Config/Config.hpp"
#include "Werk/Config/IniConfigSource.hpp"
#include "Werk/Logging/AsyncLog.hpp"
#include "Werk/Logging/LogManager.hpp"
#include "Werk/Profiling/ProfileManager.hpp"
#include "Werk/Threading/BackgroundThread.hpp"
#include "Werk/Threading/ActionQueue.hpp"

namespace werk
{

class IpcConsoleServer;

/**
 * Standard application context with all the basic components.
 */
class ApplicationContext
{
public:

	ApplicationContext(const std::string &logFilePath);
	~ApplicationContext();

	bool isShutdown();
	void shutdown();

	//Configuration
	bool isRealTime() const { return _realTime; }
	bool isSimulation() const { return _simulation; }
	std::vector<std::string> &startupCommands() { return _startupCommands; }
	const std::vector<std::string> &startupCommands() const { return _startupCommands; }
	std::vector<std::string> &shutdownCommands() { return _shutdownCommands; }
	const std::vector<std::string> &shutdownCommands() const { return _shutdownCommands; }

	//Main thread
	const Clock &realTimeClock() const { return _realTimeClock; }
	const Clock *clock() const { return _clock; }
	ProfileManager &profileManager() { return _profileManager; }
	const ProfileManager &profileManager() const { return _profileManager; }
	std::vector<Action *> &shutdownActions() { return _shutdownActions; }
	const std::vector<Action *> &shutdownActions() const { return _shutdownActions; }

	//Background thread and tasks
	BackgroundThread &backgroundThread() { return _backgroundThread; }
	const BackgroundThread &backgroundThread() const { return _backgroundThread; }
	LogManager &logManager() { return _logManager; }
	const LogManager &logManager() const { return _logManager; }
	AsyncLog *stdoutLog() { return _stdoutLog; }
	const AsyncLog *stdoutLog() const { return _stdoutLog; }
	AsyncLog *log() { return _log; }
	const AsyncLog *log() const { return _log; }
	Config *config() { return _config; }
	const Config *config() const { return _config; }
	CommandManager *commandManager() { return _commandManager; }
	const CommandManager *commandManager() const { return _commandManager; }

private:
	bool _realTime;
	bool _simulation;
	std::vector<std::string> _startupCommands;
	std::vector<std::string> _shutdownCommands;

	Clock _realTimeClock;
	Clock *_clock;
	ProfileManager _profileManager;
	std::vector<Action *> _shutdownActions;

	BackgroundThread _backgroundThread { &_profileManager };
	ActionQueue<> _backgroundActionQueue { "BackgroundActionQueue" };
	LogManager _logManager;
	AsyncLog *_stdoutLog;
	AsyncLog *_log;
	Config *_config;
	CommandManager *_commandManager;
	std::unique_ptr<IpcConsoleServer> _consoleServer;
};

}
