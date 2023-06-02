
#include "cloud_disable.hpp"


int main()
{
    try
    {
        string sharedconfig_directory = getDirectory("Enter directory for sharedconfig.vdf: ");
        string sharedconfig_file = sharedconfig_directory + "/sharedconfig.vdf";

        string library_directory = getDirectory("Enter directory for libraryfolders.vdf: ");
        string library_file = library_directory + "/libraryfolders.vdf";

        string sharedconfig_content = readFileContents(sharedconfig_file);
        string library_content = readFileContents(library_file);

        string game_ids = extractGameIds(library_content);

        if (!game_ids.empty())
        {
            if (replaceAppsBlock(sharedconfig_file, sharedconfig_content, game_ids))
            {
                cout << "Success." << endl;
            }
        }

        cout << "Press ENTER to exit..." << endl;
        getchar();
        return 0;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
