# ofxBootstrApp
Personal-use addon that provides a base ofApp-derived class that takes care of many common tasks

## Usage

Simply have your main ofApp class inherit from the ofxBoostrApp::App instead of ofBaseApp

```c++
class ofApp : public ofxBootstrApp::App {
public:
    void setup();
    void setupParameters() override;
    void update();
    void draw();
};
```

This will by default provide the following functionality;
* setup parameters in the ofxBootstrApp::App::parameters attribute at setup (override the setupParameters method to customize)
* load parameters at setup (by default from params.xml in the data folder)
* redirect output if specified in the ofxBootstrApp::App::logFileParam attribute at setup
* set logging-level if specified by the ofxBootstrApp::App::logLevelParam attribute at setup
* save parameters at setup to file specified in the ofxBootstrApp::paramsFileParam attribute at exit

Since you're probably gonna have to apply some custom behaviour in your own class' setup and exit routines, the ofxBootstrApp::App routines have to be called explicitly, but this make it clearer in the code where these "hidden" features come from:

```c++

void ofApp::setup(){
    // ofxBootstrApp::App's setup method takes care of;
    // - setting up parameters
    // - loading parameters
    // - redirecting loggings output according to parameter configuration
    // - sets log level based on ofxBootstrApp::App::logLevelParam
    ofxBootstrApp::App::setup();

    // setup custom stuff here
}

void ofApp::exit(ofEventArgs &args){
    someEssentialParam.set(getEssentialValue());

    // ofxBootstrApp::App takes care of;
    // - saving our params
    ofxBootstrApp::App::exit(args);
}
```


## Optional features

### ofxOperations support

To enable the aumatic ofxOperations features you have to define the preprocesser macro:
``` OFXBOOTSTRAP_OFXOPERATIONS ```:

```
# config.make
PROJECT_DEFINES = OFXBOOTSTRAP_OFXOPERATIONS
```

This way the ofxOperations addon is only required if you explicitly enable it for your project. Of course you then need to add the ```ofxOperations``` addon to your project:
```
# addons.make
ofxOperations
```
