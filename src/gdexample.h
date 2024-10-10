#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>
#include "rtmidi/RtMidi.h"

namespace godot {

class GDExample : public Sprite2D {
	GDCLASS(GDExample, Sprite2D)

private:
	double time_passed;
	double amplitude;

protected:
	static void _bind_methods();

public:
	GDExample();
	~GDExample();

	void _process(double delta) override;
	void set_amplitude(const double p_amplitude);
	double get_amplitude() const;
	static String helloworld();
	static void printhelloworld();
};

} //namespace godot

#endif