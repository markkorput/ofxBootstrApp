#pragma once

#include "ofMain.h"

#ifdef OFXBOOTSTRAP_OFXOPERATIONS
    #include "ofxOperations.h"
#endif

namespace ofxBootstrApp{
    class App : public ofBaseApp {

    public:

        //! \brief Sets up and loads parameters, redirects logging output and sets applicaton-wide log-level and calculates dt
        virtual void setup();

        //! Saves parameters
        virtual void exit(ofEventArgs &args);

        //! Activates the ofxOperations launcher GUI
        virtual void keyPressed(int key);

    protected:

        //! \brief Create the parameters structure that can be saved/load
        //!
        //! This class' parameters attribute is the root of
        //! all the parameters hierarchy.
        virtual void setupParameters();

        //! Loads this class' parameters from the specified file
        virtual void loadParameters(const string& filename);

        //! Saves this class' parameters to the specified file
        virtual void saveParameters(const string& filename);

        //! \brief Redirects ofLog output to the specified file
        //!
        //! Logs a notice message before redirecting the output.
        //! Can be overwritten by child-classes to modify/overwrite/cancel behaviour
        virtual void redirectLogging(const string& filename);

        //! \brief Sets application's log-level
        //!
        //! \param level is a string-based representation of the desired log-level,
        //! possible values are; "verbose", "notice", "warning", "error", "fatal", "silent".
        //! This parameter is considered case-INsensitive and leading/trailing whitespaces are trimmed.
        virtual void setLogLevel(const string& newLevel);

    protected: // parameters

        //! Root parameters container
        ofParameterGroup parameters;

        //! Parameter that holds the filename of the file that parameters will be saved to at shutdown
        ofParameter<string> paramsFileParam;

        //! Parameter that holds a string-base drepresentation of the current version of the application
        ofParameter<string> versionParam;

        //! Parameter that holds the filename that logging output should be redirected to
        ofParameter<string> logFileParam;

        //! Parameter that specifies the desired application-wide log-level
        ofParameter<string> logLevelParam;

    protected:

        //! Time (in seconds) between frames, used in update routines
        float dt;

#ifdef OFXBOOTSTRAP_OFXOPERATIONS
        ofxOperations::OperationGroup operationsGroup;
        ofxOperations::gui::Launcher operationsLauncher;
#endif
    };
}
