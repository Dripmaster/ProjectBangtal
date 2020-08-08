// ProjectBangtal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Bangtal.h>
#include <stdio.h> 
SceneID Rooms[21];
ObjectID leftArrow;
ObjectID rightArrow;
int currentView;
int currentRoom;
int maxView;
//////////////////Room0 Objects
ObjectID board;
ObjectID desk[20];
ObjectID table;
ObjectID box;
ObjectID lightSwitch;
ObjectID jokbo1;
ObjectID ruler;
bool lightState = true;
bool box1Open = false;
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
	board = createObject("Images/Room0/Board.png");
	locateObject(board, Rooms[0], 174, 720-260);
	showObject(board);
	box = createObject("Images/Room0/boxClose.png");
	locateObject(box, Rooms[0], 589,720-334);
	showObject(box);
	table = createObject("Images/Room0/table.png");
	locateObject(table, Rooms[0], 539, 720 - 350);
	showObject(table);
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
	}

}
void SetMouseCallBackRoom0(ObjectID id, int x, int y, MouseAction action){
	if (action == MouseAction::MOUSE_CLICK) {
		if (id == box && box1Open ==false) {
			showKeypad("AAAA1",box);

		}
		if (id == lightSwitch) {
			lightState = lightState ? false : true;
		}
		float light=1;
		if (!lightState) {
			light = 0.7f;
			char path[100];
			for (int i = 0; i < 20; i++)
			{

				sprintf_s(path, "Images/Room0/Desks/desk_light (%d).png", i + 1);
				setObjectImage(desk[i],path);
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
	else if (action == MouseAction::MOUSE_DRAG_LEFT) {
		if (id == table) {
			locateObject(table,Rooms[0],389, 720 - 350);
		}
	}
	else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
		if (id == table) {
			locateObject(table, Rooms[0], 709, 720 - 350);
		}
	}
}
void init_room0() {//씬 생성해서 Rooms에 할당, 오브젝트 배치
	Rooms[0] = createScene("강의실1", "Images/Room0/backGround0.png");
	SetObjectRoom0();
	Rooms[1] = createScene("강의실2", "Images/배경-1.png");
	Rooms[2] = createScene("강의실3", "Images/배경-1.png");
	Rooms[3] = createScene("강의실4", "Images/배경-1.png");
}
void init_room1() {
	Rooms[4] = createScene("실습실1", "Images/배경-1.png");
	Rooms[5] = createScene("실습실2", "Images/배경-1.png");
	Rooms[6] = createScene("실습실3", "Images/배경-1.png");
	Rooms[7] = createScene("실습실4", "Images/배경-1.png");
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
	init_room0();
	init_room1();
	init_room2();
	init_room3();
	init_room4();
	SetArrows();
	setMouseCallback(mouseCallback);
	setSceneCallback(sceneCallback);
	setObjectCallback(objectCallback);

	startGame(Rooms[0]);
}
