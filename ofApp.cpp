#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);

	for (int i = 0; i < 80; i++) {

		auto particle = make_unique<Particle>();
		this->particles.push_back(move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 3 == 0) {

		auto particle = make_unique<Particle>();
		this->particles.push_back(move(particle));
	}

	for (int i = this->particles.size() - 1; i > -1; i--) {

		this->particles[i]->think(this->particles);
		if (this->particles[i]->isDead()) {

			this->particles.erase(this->particles.begin() + i);
		}
	}

	for (auto& particle : this->particles) {

		particle->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (auto& particle : this->particles) {

		particle->draw();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}