// Author: Owen Merkling,,, <omerkling@gmail.com>, (C) 2008
//
// Copyright: For use by the students of CS 240 at BYU
//
//

#include <gtkmm/main.h>
#include <glib.h>
#include "ChessGuiImages.h"
#include "Chess.h"

#include "ChessControllerImpl.h"

#include <iostream>
using namespace std;


///@file main.cpp
///@ingroup backend
///Locates and loads default images and glade file. Drives the Chess class.
///Does not need to be modified, but may be if so desired,
///or if the value of #GLADE_FILE or #IMAGE_PATH needs to be changed
///because of differences in directory structure.

///@def GLADE_FILE
///The loacation of the glade file relative to the loaction of the executable.
///See @link cs240chess.glade "Glade File" @endlink
#define GLADE_FILE "../cs240chess.glade"

///@def IMAGE_PATH
///Location of the default image directory relative to the exectuable
#define IMAGE_PATH "../view/images/"

///@def NO_GUI_LOG
///If defined all non-fatal logging messages from the GUI will be hidden
#define NO_GUI_LOG

///A dummy handler to hide non-fatal messeges from the GUI
///@ingroup chessgui
void ChessGui_log_handler(const gchar *log_domain,
						  GLogLevelFlags log_level,
						  const gchar *message, gpointer user_data)
{
	return;
}


int main(int argc,char ** argv)
{
	///Parses path to executable for loading default images and gladeFile
	std::string path(argv[0]);
	int dirFinder = path.find_last_of('/');
	path=path.substr(0,dirFinder+1);


	///Resolves the path of the executable with GLADE_FILE
	std::string gladeFile(path + GLADE_FILE);

	#ifdef NO_GUI_LOG
	int logId = g_log_set_handler("ChessGui",G_LOG_LEVEL_MASK,ChessGui_log_handler,0);
	#endif

	try
	{
        Gtk::Main myapp(argc,argv);

		///Loads default images based off the path to the executable and IMAGE_PATH
		ChessGuiImages::LoadImages(std::string(path+IMAGE_PATH));

		
		///Initialize Chess game using glade file
		// note: chess used to be called game
		Chess chess(gladeFile);
		
		///Create your instance of the ChessController interface here and connect it to
		///the game object using the SetView method.  Don't forget to connect the game
		///object to your ChessController object using the SetController method.
		
		//DbgMsg("init game");
		ChessGame game;
		//DbgMsg("init controller");
		ChessControllerImpl controller(&game);
		//DbgMsg("set view");
		controller.SetView(&chess);
		//DbgMsg("set controller");
		chess.SetController(&controller);
		
		///run game
		chess.run(myapp);
		
	}
	catch(std::exception & e)
	{
		g_warning(e.what());
		return 1;
	}
	catch(...)
	{
		g_warning("Unknown Error Occurred, Terminating");
		return 1;
	}

	#ifdef NO_GUI_LOG
	g_log_remove_handler("ChessGui",logId);
	#endif

	return 0;
}



