#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    

    ofRegisterURLNotification(this);
    
    int id = ofLoadURLAsync("http://localhost:8000/",
                            "async_req");
    
   

}

//--------------------------------------------------------------
void ofApp::update(){
    
    twitchPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    
    if(twitchPlayer.isLoaded()) {
        
        twitchPlayer.draw(0.0, 0.0);
        ofLogNotice("video loaded");
        
        if(twitchPlayer.isFrameNew()) {
            
            if(nFramesRecorded <= 1500) {
                img.grabScreen(0, 0 , 280, 280);
                img.save( ofToString(nFramesRecorded) + ".png");
                nFramesRecorded++;
            }
        }
        
    } else {
        ofLogNotice("video not loaded");

    }

}
//--------------------------------------------------------------

void ofApp::urlResponse(ofHttpResponse & response) {
    if (response.status==200 && response.request.name == "async_req") {
        

        ofJson resultJson = ofJson::parse(response.data);
        loadVideo(resultJson[0]["url"]);
        nFramesRecorded = 0;
    
    } else {
      cout << response.status << " " << response.error << endl;
      
    }
}

//--------------------------------------------------------------
void ofApp::loadVideo(string url) {
    twitchPlayer.load(url);
    twitchPlayer.play();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
