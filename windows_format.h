#pragma once
#include <proc_inputs.h>
#include <input_box.h>

const char* Title = { "Bitwise operations" };
const char* Guide = { " You can insert: \n 1) An hex number in 0x0 notation \n 2) An Hex number followed by space toggle \n 3) Two hex numbers in 0x0 notation with a logic operator" };
const char* input_string = "";

void first_input_window() {
	InputBox((char*)Guide, (char*)Title, (char*)input_string);
}