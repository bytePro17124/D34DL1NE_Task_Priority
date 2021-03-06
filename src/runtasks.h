#pragma once
#ifndef _RUNTASKS_H_
#define _RUNTASKS_H_
#include "task.h"
#include <utility>
#include <vector>
#include <ctime>

class Task;

class Date;

class RunTasks {

public:

	friend bool operator< (const Task& T1, const Task& T2);

	RunTasks();  //built in runtasks.cpp

	void exec();  //built in runtasks.cpp

private:

	//date time holding variables
	std::time_t now;
	tm *ltm;

	std::vector<Task> allTasks;  //holds all live tasks

	std::string latestMessage;  //variable to display the user status updates

	int menu(std::pair<int, int>& __minmax);  //built in runtasks.cpp

	void createNewTask(void);  //built in runtasks.cpp

	void createNewTask(std::vector<Task> &inctasks);  //built in runtasks.cpp

	void viewAllTasks(void);  //built in runtasks.cpp

	void viewHighestPriorityTask(void);  //built in runtasks.cpp

	void printCurrentTime(void);  //built in runtasks.cpp

	void removeTask(void);  //built in runtasks.cpp

	void editTask(void);  //edit task submenu to make any changes to an existing task

	const char *user_dir;

	bool loadTasklist(const std::string filename);  //loads up saved tasks. built in runtasks_save_load.cpp

	bool saveTasklist(const std::string filename);  //saves working tasks for later use. built in runtasks_save_load.cpp

	std::vector<std::string> pendingHistory;  //to write out on save

	void addTaskToPendingHistory(Task &);

	void writePendingHistory();  //writes new history to log file and clears pendingHistory vector

	void showHistory();  //shows entire history of completed tasks

	//To build...
	//
	//

	//Mark a task as complete option - not sure if this is going to be used
	// void markTaskComplete(const std::size_t loc);

	//prompt removal of all out of date tasks
	// void cleanTaskList(void);

	//based on exact name
	// void removeTask(const std::string taskname);

};

#endif
