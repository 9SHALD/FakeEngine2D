#ifndef INPUT_H
#define INPUT_H

#include <GL/glew.h>
#include <glfw3.h>

// KeyCode used by Input
enum KeyCode {

	Mouse1 = GLFW_MOUSE_BUTTON_1,
	Mouse2 = GLFW_MOUSE_BUTTON_2,
	Mouse3 = GLFW_MOUSE_BUTTON_3,
	Mouse4 = GLFW_MOUSE_BUTTON_4,
	Mouse5 = GLFW_MOUSE_BUTTON_5,
	Mouse6 = GLFW_MOUSE_BUTTON_6,
	Mouse7 = GLFW_MOUSE_BUTTON_7,
	Mouse8 = GLFW_MOUSE_BUTTON_8,

	MouseLeft = GLFW_MOUSE_BUTTON_LEFT,
	MouseRight = GLFW_MOUSE_BUTTON_RIGHT,
	MouseMiddle = GLFW_MOUSE_BUTTON_MIDDLE,
	LastButton = GLFW_MOUSE_BUTTON_LAST,

	Space = 32,
	Apostrophe = 39,
	Comma = 44,
	Minus = 45,
	Period = 46,
	Slash = 47,
	Alpha0 = 48,
	Alpha1 = 49,
	Alpha2 = 50,
	Alpha3 = 51,
	Alpha4 = 52,
	Alpha5 = 53,
	Alpha6 = 54,
	Alpha7 = 55,
	Alpha8 = 56,
	Alpha9 = 57,
	Semicolon = 59,
	Equal = 61,
	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,
	LeftBracket = 91,
	Backslash = 92,
	RightBracket = 93,
	GraveAccent = 96,
	Escape = 256,
	Enter = 257,
	Tab = 258,
	Backspace = 259,
	Insert = 260,
	Delete = 261,
	Right = 262,
	Left = 263,
	Down = 264,
	Up = 265,
	PageUp = 266,
	PageDown = 267,
	Home = 268,
	End = 269,
	CapsLock = 280,
	ScrollLock = 281,
	NumLock = 282,
	PrintScreen = 283,
	Pause = 284,
	F1 = 290,
	F2 = 291,
	F3 = 292,
	F4 = 293,
	F5 = 294,
	F6 = 295,
	F7 = 296,
	F8 = 297,
	F9 = 298,
	F10 = 299,
	F11 = 300,
	F12 = 301,
	F13 = 302,
	F14 = 303,
	F15 = 304,
	F16 = 305,
	F17 = 306,
	F18 = 307,
	F19 = 308,
	F20 = 309,
	F21 = 310,
	F22 = 311,
	F23 = 312,
	F24 = 313,
	F25 = 314,
	KeyPad0 = 320,
	KeyPad1 = 321,
	KeyPad2 = 322,
	KeyPad3 = 323,
	KeyPad4 = 324,
	KeyPad5 = 325,
	KeyPad6 = 326,
	KeyPad7 = 327,
	KeyPad8 = 328,
	KeyPad9 = 329,
	KeyPadDecimal = 330,
	KeyPadDivide = 331,
	KeyPadMultiply = 332,
	KeyPadSubtract = 333,
	KeyPadAdd = 334,
	KeyPadEnter = 335,
	KeyPadEqual = 336,
	LeftShift = 340,
	LeftControl = 341,
	LeftAlt = 342,
	LeftSuper = 343,
	RightShift = 344,
	RightControl = 345,
	RightAlt = 346,
	RightSuper = 347,
	Menu = 348,
	LastKey = GLFW_KEY_LAST,
};

class Input {
public:
	static Input* getInstance();
	Input();
	virtual ~Input();

	void updateInput();
	void init(GLFWwindow* window);
	double getMouseX() { return _mouseX; }
	double getMouseY() { return _mouseY; }

	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getKeyUp(int keyCode);

	bool getButton(int keyCode);
	bool getButtonDown(int keyCode);
	bool getButtonUp(int keyCode);

private:
	static Input* instance;
	GLFWwindow* _window;

	void handleKey(unsigned int key);
	void handleMouse(unsigned int button);

	bool _keys[LastKey];
	bool _keysDown[LastKey];
	bool _keysPressed[LastKey];

	bool _buttons[LastButton];
	bool _buttonsDown[LastButton];
	bool _buttonsPressed[LastButton];

	double _mouseX;
	double _mouseY;
};

#endif
