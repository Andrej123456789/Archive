#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <map>
#include <vector>

#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;

#ifdef _WIN32
	#include <Windows.h>

	static BOOL WINAPI end(DWORD dwCtrlType)
	{
		int key;
	
		switch (dwCtrlType)
		{
			case CTRL_C_EVENT: // Ctrl+C
				std::cout << "\nPress any key to continue...\n";
				key = std::cin.get();
				if (key != 10)
				{
					/* we need to do something here; input is broken */
					exit(0);
				}
				else
				{
					exit(0);
				}
				break;
			case CTRL_BREAK_EVENT: // Ctrl+Break
				break;
			case CTRL_CLOSE_EVENT: // Closing the console window
				break;
			case CTRL_LOGOFF_EVENT: // User logs off. Passed only to services!
				break;
			case CTRL_SHUTDOWN_EVENT: // System is shutting down. Passed only to services!
				break;
		}

		// Return TRUE if handled this message, further handler functions won't be called.
		// Return FALSE to pass this message to further handlers until default handler calls ExitProcess().
		return FALSE;
	}
#elif _WIN64
	#include <Windows.h>

	static BOOL WINAPI end(DWORD dwCtrlType)
	{
		int key;

		switch (dwCtrlType)
		{
			case CTRL_C_EVENT: // Ctrl+C
				std::cout << "\nPress any key to continue...\n";
				key = std::cin.get();
				if (key != 10)
				{
					/* we need to do something here; input is broken */
					exit(0);
				}
				else
				{
					exit(0);
				}
				break;
			case CTRL_BREAK_EVENT: // Ctrl+Break
				break;
			case CTRL_CLOSE_EVENT: // Closing the console window
				break;
			case CTRL_LOGOFF_EVENT: // User logs off. Passed only to services!
				break;
			case CTRL_SHUTDOWN_EVENT: // System is shutting down. Passed only to services!
				break;
		}

		// Return TRUE if handled this message, further handler functions won't be called.
		// Return FALSE to pass this message to further handlers until default handler calls ExitProcess().
		return FALSE;
	}
#elif __APPLE__ || __MACH__
	#include <signal.h>
	struct sigaction sigIntHandler;
#elif __linux__
	#include <signal.h>
	struct sigaction sigIntHandler;

	void end(int sig)
	{
		std::cout << "\nPress any key to continue...\n";
		auto key = std::cin.get();
		if (key != 10)
		{
			/* we need to do something here; input is broken */
			exit(0);
		}
		else
		{
			exit(sig);
		}
	}
#elif __FreeBSD__
	#include <signal.h>
	struct sigaction sigIntHandler;
#elif __unix || __unix__
	#pragma message ("Unsupported!")
#else
	#pragma message ("Unsupported!")
#endif

using namespace std;

vector<string> names = {"Test", "New"};
vector<int> row = {};

map<string, int> students = 
{

};

/* Check if some string start with some std::string value */
static bool isStarting (std::string const &fullString, std::string const &starting) 
{
    if (fullString.length() <= starting.length()) { return true; }
    else { return false; }
}

int init()
{
	row.clear();

	sort(names.begin(), names.end());

	for (size_t i = 1; i < names.size() + 1; i++)
	{
		row.push_back(i);
	}
	
	try
	{
		for (auto const& [name, row2] : boost::combine(names, row))
		{
			auto position(end(students));
			position = students.insert
			(
				position,
				{
					name,
					row2
				}
			);
		}

		return 0;
	}

	catch (const std::exception& e)
	{
		cout << "Cathed exception: '" << e.what() << "'!\nReturning error...\n";
		return 1;
	}
};

void Add(string name)
{
	names.push_back(name);
	init();
}

void Remove(string name)
{
	for (auto i = names.begin(); i != names.end(); ++i)
	{
		if (*i == name)
		{
			names.erase(i);
			i--;
		}
	}

	students.clear();
	init();
}

void Open()
{
	string path, name, temp;
	int order;

	cout << "Enter name: ";
	cin >> name;

	path = name += ".txt";

	fstream my_file;
	my_file.open(path);

	Remove(name);

	if (my_file.is_open())
	{
		bool result;
		while (getline(my_file, temp))
		{
			result = isStarting(temp, "Order");
			if (result == true)
			{
				Add(temp);
			}
		}

		init();
		my_file.close();
	}
	else
	{
		cout << "Unable to open file!\n";
		return;
	}
}

void Help()
{
	cout << "Help: \n";
	cout << "a - show all students\n";
	cout << "+ - add new name to 'names' list\n";
	cout << "s - save information about student to file\n";
};

int main(int argc, const char **argv)
{
	string temp_name;
	char selection;

	bool wasFound = false;

	#ifdef _WIN32
		SetConsoleCtrlHandler(end, TRUE);
	#elif _WIN64
		SetConsoleCtrlHandler(end, TRUE);
	#elif __APPLE__ || __MACH__
		sigIntHandler.sa_handler = end;
		sigemptyset(&sigIntHandler.sa_mask);
		sigIntHandler.sa_flags = 0;
		sigaction(SIGINT, &sigIntHandler, NULL);
	#elif __linux__
		sigIntHandler.sa_handler = end;
		sigemptyset(&sigIntHandler.sa_mask);
		sigIntHandler.sa_flags = 0;
		sigaction(SIGINT, &sigIntHandler, NULL);
	#elif __FreeBSD__
		sigIntHandler.sa_handler = end;
		sigemptyset(&sigIntHandler.sa_mask);
		sigIntHandler.sa_flags = 0;
		sigaction(SIGINT, &sigIntHandler, NULL);
	#elif __unix || __unix__
		#pragma message ("Unsupported!")
	#else
		#pragma message ("Unsupported!")
	#endif

	cout << "e-notebook v0.5\n";
	char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
	cout << "Current path: " << cwd << "\n";

	if (init() != 0)
	{
		return 1;
	}

	if (argc != 2)
	{
		cout << "Choose an option: ";
		cin >> selection;
	}

	else
	{
		selection = argv[1][0];
	}

	while (selection != 'x')
	{
		switch (selection)
		{
			case 'a':
				for (auto& x : students)
				{
					cout << "Name: " << x.first << " | Order: " << x.second << "\n";
				}

				break;

			case '+':
				cout << "Enter name: ";
				cin >> temp_name;
				Add(temp_name);
				temp_name.clear();
				break;

			case '-':
				cout << "Enter name to remove: ";
				cin >> temp_name;
				Remove(temp_name);
				temp_name.clear();
				break;

			case 's':
				cout << "Enter name: ";
				cin >> temp_name;

				for (auto& x : students)
				{
					if (x.first == temp_name)
					{
						string new_name = temp_name += ".txt";
						FILE* student_file = fopen(new_name.c_str(), "w");
						fprintf(student_file, "Name %s\n", temp_name.c_str());
						fprintf(student_file, "Order %d\n", x.second);
						fclose(student_file);
						wasFound = true;
						goto end;
					}

					else
					{
						wasFound = false;
					}
				}

				if (wasFound == false)
				{
					cout << "Name wasn't found!\n";
				}

				end:
					temp_name.clear();
					break;

			case 'o':
				Open();
				break;

			case 'h':
				Help();
				break;

			case 'x':
				break;

			default:
				Help();
				break;
		}

		cout << "Choose an option: ";
		cin >> selection;
	}

	return 0;
}