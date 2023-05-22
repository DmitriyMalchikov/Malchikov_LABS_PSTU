#include "Dialog.h"
void Dialog::Execute() {
	TEvent event;
	while (Valid()) {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	}
}

Dialog::Dialog(void) :Vector() {
	EndState = 0;
}

Dialog::~Dialog(void) {}


bool Dialog::Valid() {
	return EndState == 0;
}

void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake:
			cout << "Enter size: "; cin >> size;
			beg = new Object * [size];
			curr = 0;
			cout << "Group has been created!" << endl;
			ClearEvent(event);
			break;
		case cmAdd:
			add(); ClearEvent(event); break;
		case cmDel:
			del(); ClearEvent(event); break;
		case cmGet:
			getname(); ClearEvent(event); break;
		case cmShow:
			show(); ClearEvent(event); break;
		case cmQuit:
			EndExec(); ClearEvent(event); break;
		}
	}
}

void Dialog::GetEvent(TEvent& event) {
	string command = "m+-szq";
	string s;
	char code;
	cout << "Enter command(m+-szq): "; cin >> s;
	code = s[0];
	if (command.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break;
		}
	}
	else event.what = evNothing;
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}

void Dialog::EndExec() {
	EndState = 1;
}