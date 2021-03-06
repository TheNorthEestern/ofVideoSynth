#pragma once

#include "ofxGui.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    const string settingsFileName = "settings.xml";
    void setup();
    void update();
    void draw();
    void exit();
    void stripePattern();
    void matrixPattern();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofParameterGroup configureTitle(string title);

    bool showGui = true;
    
    ofxPanel gui;
    ofxIntSlider countX;
    ofxFloatSlider stepX;
    ofxFloatSlider twistX;
    
    ofxGuiGroup globalGroup;
    ofxFloatSlider Scale;
    ofxFloatSlider Rotate;
    ofxFloatSlider Background;
    
    ofxGuiGroup primGroup;
    ofxFloatSlider shiftY, rotate;
    ofxVec2Slider size;
    ofxColorSlider color;
    ofxToggle filled, type;
    
    ofxIntSlider countY;
    ofxFloatSlider stepY, twistY, pinchY;
};
