// ProjectBangtal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Bangtal.h>
SceneID Rooms[21];
ObjectID leftArrow;
ObjectID rightArrow;
int currentView;
int currentRoom;
int maxView;
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
void init_room0() {//씬 생성해서 Rooms에 할당, 오브젝트 배치
	Rooms[0] = createScene("강의실1", "Images/배경-1.png");
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
	Rooms[8] = createScene("백마관 앞1", "Images/배경-1.png");
	Rooms[9] = createScene("백마관 앞2", "Images/배경-1.png");
	Rooms[10] = createScene("백마관 앞3", "Images/배경-1.png");
	Rooms[11] = createScene("백마관 앞4", "Images/배경-1.png");
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
	setMouseCallback(arrawCallback);
	setSceneCallback(sceneCallback);

	startGame(Rooms[0]);
}
