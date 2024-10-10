#include "gdexample.h"

using namespace godot;

void GDExample::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_amplitude"), &GDExample::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDExample::set_amplitude);
	ClassDB::bind_static_method("GDExample", D_METHOD("hello_world"), &GDExample::helloworld);
	ClassDB::bind_static_method("GDExample", D_METHOD("print_hello_world"), &GDExample::printhelloworld);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
}

GDExample::GDExample() {
	// Initialize any variables here.
	time_passed = 0.0;
	amplitude = 10.0;
	//GDExample::printhelloworld();
}

GDExample::~GDExample() {
	// Add your cleanup here.
}

void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_position = Vector2(amplitude + (amplitude * sin(time_passed * 2.0)), amplitude + (amplitude * cos(time_passed * 1.5)));

	set_position(new_position);
}

void GDExample::set_amplitude(double p_amplitude) {
	amplitude = p_amplitude;
}

double GDExample::get_amplitude() const {
	return amplitude;
}

String GDExample::helloworld() {
	// RtMidiOut *midiout = new RtMidiOut();
	// std::vector<unsigned char> message;
	// unsigned int nPorts = midiout->getPortCount();
	// if (nPorts == 0) {
	// 	UtilityFunctions::print("No ports available!\n");
	// 	// goto cleanup;
	// }

	// midiout->openPort(0);
	// message.push_back(192);
	// message.push_back(5);
	// midiout->sendMessage(&message);

	// cleanup:
	// 	delete midiout;

	RtMidiIn *midiin = 0;
	RtMidiOut *midiout = 0;

	// RtMidiIn constructor
	try {
		midiin = new RtMidiIn();
	} catch (RtMidiError &error) {
		UtilityFunctions::print("Well no");
	}

	return "Hello world";
}

void GDExample::printhelloworld() {
	UtilityFunctions::print("Heallow woarld!");
}