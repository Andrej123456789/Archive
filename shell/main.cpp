#include <iostream>
#include <string>
#include <map>

#include <signal.h> /* posix only */

void ok()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Successfully executed!\n");
}

void not_ok()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Not successfully executed!\n");
}

struct sigaction sigIntHandler; /* posix only */

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

static std::map<std::string, std::string> commands = 
{
    {"calc", "./commands/calc"} /* for windows you need chnage path here */
};

int main()
{
    using namespace std;
    string input;

    /* Catch CTRL-C  (posix only)*/
	sigIntHandler.sa_handler = end;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);

    while (true)
    {
        cout << "Termi> ";
        getline(cin, input);

        auto command = commands.find(input);

        if (command != commands.end())
        {
            if (system(command->second.c_str()) == 0)
            {
                ok();
            }

            else
            {
                not_ok();
            }
        }

        else if (input == "help")
        {
            for (auto& x : commands)
            {
                cout << x.first << endl;
            }

            ok();
        }

        else if (input == "clear" || input == "cls")
        {
            cout << "\033c";
        }

        else if (input == "exit")
        {
            exit(0);
        }

        else if (input.length() == 0) /* enter */
        {
            
        }

        else
        {
            cout << "Wrong command!\n";
            not_ok();
        }
    }

    return 0;
}
