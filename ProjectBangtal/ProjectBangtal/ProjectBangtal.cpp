// ProjectBangtal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Bangtal.h>
#include <stdio.h> 

SceneID titleScene;
ObjectID startBtn;
//////////////////
SceneID Rooms[21];
ObjectID leftArrow;
ObjectID rightArrow;
int currentView;
int currentRoom;
int maxView;
//////////////////Room0 Objects
ObjectID board;
ObjectID desk[20];
ObjectID studyTable;
ObjectID box;
ObjectID lightSwitch;
ObjectID jokbo1;
ObjectID ruler;
bool lightState = true;
bool box1Open = false;


ObjectID r0_door1;
ObjectID r0_door2;
bool r0_door1Open = false;

ObjectID picture[4];

ObjectID window;
ObjectID hitter;
bool windowOpen = true;
////////////////////
void sceneCallback(SceneID scene, EventID event)
{
	if (scene == Rooms[0]) {
		if (event == EventID::EVENT_ENTER_SCENE) {

		}
	}
}
void arrawCallback(ObjectID id, int x, int y, MouseAction action)
{
	if (action == MouseAction::MOUSE_CLICK) {
		bool changeScene = false;
		if (id == leftArrow) {
			currentView--;
			changeScene = true;
		}
		else if (id == rightArrow) {
			currentView++;
			changeScene = true;
		}
		if (currentView < 0)
			currentView = maxView-1;
		if (currentView >= maxView)
			currentView = 0;
		if (changeScene == true) {

			locateObject(leftArrow, Rooms[currentView + currentRoom * 4], 10, 100);
			locateObject(rightArrow, Rooms[currentView + currentRoom * 4], 1200, 100);
			enterScene(Rooms[currentView+ currentRoom *4]);
		}
	}
}
void SetArrows() {

	leftArrow = createObject("Images/left.png");
	rightArrow = createObject("Images/right.png");
	locateObject(leftArrow, Rooms[currentView], 10, 100);
	locateObject(rightArrow, Rooms[currentView], 1200, 100);
	showObject(leftArrow);
	showObject(rightArrow);
}
void changeRoom(int RoomNumber) {
	currentView = 0;
	currentRoom = RoomNumber;
	locateObject(leftArrow, Rooms[RoomNumber*4], 10, 100);
	locateObject(rightArrow, Rooms[RoomNumber*4], 1200, 100);
	enterScene(Rooms[RoomNumber*4]);
}
void SetObjectRoom0(){
	//전면
	board = createObject("Images/Room0/Board.png");
	locateObject(board, Rooms[0], 174, 720-260);
	showObject(board);
	box = createObject("Images/Room0/boxClose.png");
	locateObject(box, Rooms[0], 589,720-334);
	showObject(box);
	studyTable = createObject("Images/Room0/table.png");
	locateObject(studyTable, Rooms[0], 539, 720 - 350);
	showObject(studyTable);
	lightSwitch = createObject("Images/Room0/Light_on.png");
	locateObject(lightSwitch, Rooms[0], 1127, 720 - 180);
	showObject(lightSwitch);
	jokbo1 = createObject("Images/Room0/jokbo1.png");
	ruler = createObject("Images/Room0/ruler.png");

	char path[100];
	for (int i = 0; i < 20; i++)
	{
	
		sprintf_s(path, "Images/Room0/Desks/desk (%d).png", i+1);
		desk[i] = createObject(path);

		locateObject(desk[i], Rooms[0], 280+(i%5)*150, 720-420-(i/5)*100);
		showObject(desk[i]);
	}

	///측면(우)
	r0_door1 = createObject("Images/Room0/door_close.png");
	locateObject(r0_door1, Rooms[1], 170, 130);
	showObject(r0_door1);
	r0_door2 = createObject("Images/Room0/door_closeX.png");
	locateObject(r0_door2, Rooms[1], 860, 15);
	showObject(r0_door2);

	///측면(좌)
	hitter = createObject("Images/Room0/hitter.png");
	locateObject(hitter, Rooms[3], 60, -20);
	showObject(hitter);
	window = createObject("Images/Room0/window_open.png");
	locateObject(window, Rooms[3], 10, 150 );
	showObject(window);


	///후면
	for (int i = 0; i < 4; i++)
	{

		sprintf_s(path, "Images/Room0/picture%d.png", i + 1);
		picture[i] = createObject(path);

		locateObject(picture[i], Rooms[2],200+i*250,360);
		showObject(picture[i]);
	}
}
ObjectID r1_door1;
ObjectID clock;
ObjectID display;
ObjectID ironBoard;
ObjectID table1;
ObjectID table2;
ObjectID table3;
ObjectID whiteBoard;

ObjectID r1_door2;
ObjectID display2;
ObjectID table1_2;
ObjectID table2_2;
ObjectID table3_2; 

ObjectID r1_door3;
ObjectID clock2;
ObjectID display3;
ObjectID table1_3;
ObjectID table2_3;
ObjectID table3_3; 
ObjectID whiteBoard2;

ObjectID r1_door4;
ObjectID clock3;
ObjectID ironBoard2;
ObjectID whiteBoard3;
void SetObjectRoom1() {
	//전면
	r1_door1 = createObject("Images/Room1/실습실_1면/실습실 1면 문.png");
	clock = createObject("Images/Room1/실습실_1면/실습실 1면 시계.png");
	ironBoard = createObject("Images/Room1/실습실_1면/실습실 1면 철판.png");
	table1 = createObject("Images/Room1/실습실_1면/실습실 1면 탁자1.png");
	table2 = createObject("Images/Room1/실습실_1면/실습실 1면 탁자2.png");
	table3 = createObject("Images/Room1/실습실_1면/실습실 1면 탁자3.png");
	display = createObject("Images/Room1/실습실_1면/실습실 1면 유리장식장.png");
	whiteBoard = createObject("Images/Room1/실습실_1면/실습실 1면 화이트보드.png");

	locateObject(r1_door1, Rooms[4], 556, 282);
	locateObject(clock, Rooms[4], 174, 573);
	locateObject(ironBoard, Rooms[4], 412, 221);
	locateObject(table1, Rooms[4], 764, 36);
	locateObject(table2, Rooms[4], 852, 239);
	locateObject(table3, Rooms[4], 852, 512);
	locateObject(display, Rooms[4], 966, 0);
	locateObject(whiteBoard, Rooms[4], 41, 208);
	///측면(우)
	r1_door2 = createObject("Images/Room1/실습실_2면/실습실 2면 문.png");
	table1_2 = createObject("Images/Room1/실습실_2면/실습실 2면 탁자1.png");
	table2_2 = createObject("Images/Room1/실습실_2면/실습실 2면 탁자2.png");
	table3_2 = createObject("Images/Room1/실습실_2면/실습실 2면 탁자3.png");
	display2 = createObject("Images/Room1/실습실_2면/실습실 2면 유리장식장.png");
	
	locateObject(r1_door2, Rooms[5], 0, 59);
	locateObject(table1_2, Rooms[5], 81, 42);
	locateObject(table2_2, Rooms[5], 160, 245);
	locateObject(table3_2, Rooms[5], 161, 473);
	locateObject(display2, Rooms[5], 815, 16);
	///측면(좌)
	r1_door3    = createObject("Images/Room1/실습실_3면/실습실 3면 문.png");
	clock2      = createObject("Images/Room1/실습실_3면/실습실 3면 시계.png");
	display3    = createObject("Images/Room1/실습실_3면/실습실 3면 유리장식장.png");
	table1_3    = createObject("Images/Room1/실습실_3면/실습실 3면 탁자1.png");
	table2_3    = createObject("Images/Room1/실습실_3면/실습실 3면 탁자2.png");
	table3_3    = createObject("Images/Room1/실습실_3면/실습실 3면 탁자3.png");
	whiteBoard2 = createObject("Images/Room1/실습실_3면/실습실 3면 화이트보드.png");

	locateObject(r1_door3, Rooms[6], 556, 282);
	locateObject(clock2, Rooms[6], 1221, 557);
	locateObject(display3, Rooms[6], 155, 80);
	locateObject(table1_3, Rooms[6], 0, 0);
	locateObject(table2_3, Rooms[6], 0, 123);
	locateObject(table3_3, Rooms[6], 0, 484);
	locateObject(whiteBoard2, Rooms[6], 1125, 188);
	///후면
	r1_door4   = createObject("Images/Room1/실습실_4면/실습실 4면 문.png");
	clock3      = createObject("Images/Room1/실습실_4면/실습실 4면 시계.png");
	ironBoard2   = createObject("Images/Room1/실습실_4면/실습실 4면 철판.png");
	whiteBoard3 = createObject("Images/Room1/실습실_4면/실습실 4면 화이트보드.png");

	locateObject(r1_door4, Rooms[7], 1237, 58);
	locateObject(clock3, Rooms[7], 634, 571);
	locateObject(ironBoard2, Rooms[7], 968, 61);
	locateObject(whiteBoard3, Rooms[7], 366, 230);
	//
	showObject(r1_door1);
	showObject(clock);
	showObject(ironBoard);
	showObject(table1);
	showObject(table2);
	showObject(table3);
	showObject(display);
	showObject(whiteBoard);
	showObject(r1_door2);
	showObject(display2);
	showObject(table1_2);
	showObject(table2_2);
	showObject(table3_2);
	showObject(r1_door3);
	showObject(clock2);
	showObject(display3);
	showObject(table1_3);
	showObject(table2_3);
	showObject(table3_3);
	showObject(whiteBoard2);
	showObject(r1_door4);
	showObject(clock3);
	showObject(ironBoard2);
	showObject(whiteBoard3);
}
void SetObjectCallbackRoom0(ObjectID id, EventID event) {
	if (event == EventID::EVENT_KEYPAD) {
		if (id == box) {
			box1Open = true;
			setObjectImage(box,"Images/Room0/boxOpen.png");
			showMessage("족보 조각과 자를 획득했다.");
			pickObject(jokbo1);
			pickObject(ruler);
		}
		if (id == r0_door1) {
			r0_door1Open = true;
			setObjectImage(r0_door1, "Images/Room0/door_open.png");
			showMessage("나갈 수 있는 문이 열렸다.");
		}
	}
}
void SetMouseCallBackRoom0(ObjectID id, int x, int y, MouseAction action){
	if (action == MouseAction::MOUSE_CLICK) {
		if (id == box && box1Open ==false) {
			showKeypad("GAJA1",box);
		}
		else if (id == lightSwitch) {
			lightState = lightState ? false : true; 
			float light = 1;
			if (!lightState) {
				light = 0.7f;
				char path[100];
				for (int i = 0; i < 20; i++)
				{
					sprintf_s(path, "Images/Room0/Desks/desk_light (%d).png", i + 1);
					setObjectImage(desk[i], path);
				}
			}
			else {
				char path[100];
				for (int i = 0; i < 20; i++)
				{

					sprintf_s(path, "Images/Room0/Desks/desk (%d).png", i + 1);
					setObjectImage(desk[i], path);
				}
			}
			for (int i = 0; i < 4; i++)
			{
				setSceneLight(Rooms[i], light);
			}
		}
		else if (id == window) {
			windowOpen = !windowOpen;
			if (windowOpen)
				setObjectImage(window, "Images/Room0/window_open.png");
			else
				setObjectImage(window, "Images/Room0/window_close.png");

		}
		else if (id == hitter) {
			if (!windowOpen) {
				setObjectImage(window, "Images/Room0/window_close_hit.png");
			}
		}
		else if (id == r0_door1) {
			if(r0_door1Open == false)
			showKeypad("FJCG", r0_door1);
			else {
				changeRoom(1);
			}
		}
		else if (id == r0_door2) {
			showMessage("이 문은 바깥에서 잠겨있는 것 같다.");
		}
		else  {
			for (int i = 0; i < 4; i++)
			{
				if (id == picture[i]) {
					char path[100];
					if(getHandObject()==ruler)
					sprintf_s(path, "Images/Room0/picture%d_on.png", i + 1);
					else
						sprintf_s(path, "Images/Room0/picture%d.png", i + 1);

					showImageViewer(path);
				}
			}
			
		}
	}
	else if (action == MouseAction::MOUSE_DRAG_LEFT) {
		if (id == studyTable) {
			locateObject(studyTable,Rooms[0],389, 720 - 350);
		}
	}
	else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
		if (id == studyTable) {
			locateObject(studyTable, Rooms[0], 709, 720 - 350);
		}
	}
}
void init_room0() {//씬 생성해서 Rooms에 할당, 오브젝트 배치
	Rooms[0] = createScene("강의실", "Images/Room0/backGround0.png");
	Rooms[1] = createScene("강의실", "Images/Room0/backGround1.png");
	Rooms[2] = createScene("강의실", "Images/Room0/backGround2.png");
	Rooms[3] = createScene("강의실", "Images/Room0/backGround3.png");
	SetObjectRoom0();
}
void init_room1() {
	Rooms[4] = createScene("실습실", "Images/Room1/실습실_1면/실습실 1면 배경.png");
	Rooms[5] = createScene("실습실", "Images/Room1/실습실_2면/실습실 2면 배경.png");
	Rooms[6] = createScene("실습실", "Images/Room1/실습실_3면/실습실 3면 배경.png");
	Rooms[7] = createScene("실습실", "Images/Room1/실습실_4면/실습실 4면 배경.png");
	SetObjectRoom1();
}
void init_room2() {
	Rooms[8] = createScene("백마상 앞1", "Images/배경-1.png");
	Rooms[9] = createScene("백마상 앞2", "Images/배경-1.png");
	Rooms[10] = createScene("백마상 앞3", "Images/배경-1.png");
	Rooms[11] = createScene("백마상 앞4", "Images/배경-1.png");
}
void init_room3() {
	Rooms[12] = createScene("도서관1", "Images/배경-1.png");
	Rooms[13] = createScene("도서관2", "Images/배경-1.png");
	Rooms[14] = createScene("도서관3", "Images/배경-1.png");
	Rooms[15] = createScene("도서관4", "Images/배경-1.png");
	Rooms[20] = createScene("도서관5", "Images/배경-1.png");
}
void init_room4() {
	Rooms[16] = createScene("비밀의방1", "Images/배경-1.png");
	Rooms[17] = createScene("비밀의방2", "Images/배경-1.png");
	Rooms[18] = createScene("비밀의방3", "Images/배경-1.png");
	Rooms[19] = createScene("비밀의방4", "Images/배경-1.png");
}
void mouseCallback(ObjectID id, int x, int y, MouseAction action) {
	if (id == startBtn && action == MouseAction::MOUSE_CLICK) {
		enterScene(Rooms[currentRoom * 4]);


		setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, 1);
		setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, 1);
		setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, 1);

	}
	arrawCallback(id, x, y, action);
	SetMouseCallBackRoom0(id, x, y, action);
}
void objectCallback(ObjectID id, EventID event) {
	SetObjectCallbackRoom0(id,event);
}
int main()
{
	maxView = 4;
	currentView = 0;


	titleScene = createScene("title", "Images/title/backGround.png");
	startBtn = createObject("Images/title/startBtn.png");
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, 0);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, 0);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, 0);
	locateObject(startBtn, titleScene, 170, 130);
	showObject(startBtn);

	init_room0();
	init_room1();
	init_room2();
	init_room3();
	init_room4();
	SetArrows();
	setMouseCallback(mouseCallback);
	setSceneCallback(sceneCallback);
	setObjectCallback(objectCallback);

	changeRoom(0);
	startGame(titleScene);
}
