#include <iostream>
using namespace std;
#include "Tetris.h"
#include "TetrisLine.h"
#include "TetrisSquare.h"
#include "KeyboardMessage.h"
#include "MoveTetrisHandler.h"
#include "PlayingState.h"
#include "KeyDownHandler.h"
#include "GameFram.h"
#include "CommonMessage.h"
#include "TetrisFactory.h"
#include "GameMap.h"
#include "ENU_KEY.h"
void test_rotate()
{
	cout << "Begin test_rotate():\n";
	Tetris *ter = new Tetris(TYP_TETRIS_1);
	cout << "type = " << ter->getType() << endl;
	cout << "position = " << ter->getPosition() << endl;
	cout << "Begin rotate\n";
	cout << *(TetrisBase*)(ter) << endl;
	ter->rotate(90);
	cout << "after rotate 90\n";
	cout << *(TetrisBase*)(ter) << endl;
	ter->rotate(180);
	cout << "after rotate 180\n";
	cout << *(TetrisBase*)(ter) << endl;
	cout << "after rotate 270\n";
	ter->rotate(270);
	cout << *(TetrisBase*)(ter) << endl;
	delete ter;
	cout << "end test_rotate():\n\n";
}
void test_otherTetris()
{
	cout << "Begin test_otherTetris():\n";
	for (int i = 0; i < 5; ++i)
	{
		Tetris *ter = new Tetris((PDCTYPE)i);
		cout << *(TetrisBase*)(ter) << endl;
		delete ter;
	}
	cout << "end test_otherTetris():\n\n";
}
void test_CreateTetrisLine()
{
	cout << "Begin test_CreateTetrisLine():\n";
	TetrisLine *ter = new TetrisLine();
	cout << *ter << endl;
	cout << "after rotate 90\n";
	ter->rotate(90);
	cout << *(TetrisBase*)(ter) << endl;
	delete ter;
	cout << "end test_CreateTetrisLine():\n\n";
}

void test_CreateTetrisSquare()
{
	cout << "Begin test_CreateTetrisSquare():\n";
	TetrisSquare *ter = new TetrisSquare();
	cout << *ter << endl;
	cout << "after rotate 90\n";
	ter->rotate(90);
	cout << *(TetrisBase*)(ter) << endl;
	delete ter;
	cout << "end test_CreateTetrisSquare():\n\n";
}

void test_memry_leak()
{
	cout << "Begin test_memry_leak():\n";
	for (int i = 0; i < 10000000; ++i)
	{
		TetrisSquare *ter = new TetrisSquare();
		delete ter;
	}
	cout << "end test_memry_leak():\n\n";
}

void test_message()
{
	cout << "Begin test_message():\n";
	MessageBase *msg = new KeyboardMessage(MSG_KEY_DOWN, KEY_UP);
	cout << "Msg type = " << msg->getMsg() << endl;
	cout << "Handleding ……\n";
	msg->setHandled();
	cout << "Now state = " << msg->ifHandled() << endl;
	delete msg;
	cout << "end test_message():\n\n";
}
void test_handler()
{
	cout << "Begin test_handler():\n";
	HandlerBase *handler = new MoveTetrisHandler();
	MessageBase *msg = new KeyboardMessage(MSG_KEY_DOWN, KEY_UP);
	handler->BeginHandle(msg);
	delete msg;
	delete handler;
	cout << "end test_handler():\n\n";
}
void test_state()
{
	cout << "Begin test_state():\n";
	HandlerBase * handler = new MoveTetrisHandler();  //移动方块的handler
	HandlerBase * handler1 = new KeyDownHandler();		//键盘按下的消息处理handler
	handler->setNextHandler(handler1);  	//创建责任链
	handler1->setNextHandler(handler);
	StateBase * state = new PlayingState(handler);
	MessageBase *msg = new KeyboardMessage(MSG_KEY_DOWN, KEY_UP);  //KeyboardMessage,按下键盘10
	state->stateHandle(msg); //此状态下开始处理消息
	delete msg;
	delete state;
	delete handler;
	delete handler1; 
	cout << "end test_state():\n\n";
}

void test_GameFram()
{
	cout << "Begin test_GameFram():\n";
	GameFram * game = GameFram::getInstance();

	cout << "end test_GameFram():\n\n";
}

void test_tetris_factory()
{
	cout << "Begin test_tetris_factory():\n";
	TetrisFactory * factory = TetrisFactory::getInstance();
	TetrisBase * tetris = factory->CreateTetris(TYP_TETRIS_1);
	cout << "My create tetris is \n";
	cout << *tetris << endl;
	cout << "Now destroy tetris \n";
	factory->DestroyTetris(tetris);
	cout << "end test_tetris_factory():\n\n";
}

void test_send_msg_to_game_fram()
{
	cout << "Begin test_send_msg_to_game_fram():\n";
	GameFram * game = GameFram::getInstance();
	MessageBase* msg = new CommonMessage(MSG_CREATE_TETRIS);
	game->PushMsg(msg);
	delete msg;
	msg = new CommonMessage(MSG_DEBUG_TRACE);
	game->PushMsg(msg);
	delete msg;
	cout << "end test_send_msg_to_game_fram():\n\n";
}

void test_PinToMap()
{
	cout << "Begin test_PinToMap():\n";
	
	for (int i = 0; i < 5; ++i)
	{
		Tetris *ter = new Tetris((PDCTYPE)i);
		cout << *(TetrisBase*)(ter) << endl;

		GameMap *map = new GameMap(10,10);
		ter->move();ter->move();ter->move();//ter->move();ter->move();
		cout << ter->getPosition()<< endl;
		ter->PinToMap(map);
		cout << *(AggregateBase*)map << endl;
		delete map;

		delete ter;
	}
	cout << "end test_PinToMap():\n\n";
}

void test_move_in_map()
{
	cout << "Begin test_move_in_map():\n";

	GameFram * game = GameFram::getInstance();
	MessageBase* msg_trace = new CommonMessage(MSG_DEBUG_TRACE);
	MessageBase* msg = new CommonMessage(MSG_CREATE_TETRIS);
	game->PushMsg(msg);
	delete msg;
	msg = new CommonMessage(MSG_UPDATE_GAME);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg_trace);
	MessageBase *msg1 = new KeyboardMessage(MSG_KEY_DOWN, KEY_RIGHT);
	game->PushMsg(msg1);
	delete msg1;

	game->PushMsg(msg);
	delete msg;

	
	game->PushMsg(msg_trace);
	delete msg_trace;

	cout << "end test_move_in_map():\n\n";
}

void test_ill_move()
{
	cout << "Begin test_ill_move():\n";

	GameFram * game = GameFram::getInstance();
	MessageBase* msg_trace = new CommonMessage(MSG_DEBUG_TRACE);
	MessageBase* msg = new CommonMessage(MSG_CREATE_TETRIS);
	game->PushMsg(msg);
	delete msg;
	msg = new CommonMessage(MSG_UPDATE_GAME);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg_trace);
	MessageBase *msg1 = new KeyboardMessage(MSG_KEY_DOWN, KEY_RIGHT);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);

	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);  //一直往右边移动
	delete msg1;

	msg1 = new KeyboardMessage(MSG_KEY_DOWN, KEY_LEFT);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);

	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);  //一直往左边移动
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);

	delete msg1;

	game->PushMsg(msg);
	delete msg;

	
	game->PushMsg(msg_trace);
	delete msg_trace;
	cout << "end test_ill_move():\n\n";

}

void test_down()
{
	cout << "Begin test_down():\n";

	GameFram * game = GameFram::getInstance();
	MessageBase* msg_trace = new CommonMessage(MSG_DEBUG_TRACE);
	MessageBase* msg = new CommonMessage(MSG_CREATE_TETRIS);
	game->PushMsg(msg);
	delete msg;
	msg = new CommonMessage(MSG_UPDATE_GAME);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg);
	game->PushMsg(msg_trace);
	MessageBase *msg1 = new KeyboardMessage(MSG_KEY_DOWN, KEY_RIGHT);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);

	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);  //一直往右边移动
	delete msg1;

	msg1 = new KeyboardMessage(MSG_KEY_DOWN, KEY_LEFT);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);

	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);  //一直往左边移动
	game->PushMsg(msg1);
	game->PushMsg(msg1);
	game->PushMsg(msg1);

	delete msg1;
	for (int i = 0; i < 2500; ++i)
	{
		game->PushMsg(msg);
	}
	delete msg;

	
	game->PushMsg(msg_trace);
	delete msg_trace;

	cout << "end test_down():\n\n";

}

void test_random_game()
{
	cout << "Begin test_random_game():\n";
	GameFram * game = GameFram::getInstance();
	MessageBase* updateMsg = new CommonMessage(MSG_UPDATE_GAME);
	MessageBase* traceMsg = new CommonMessage(MSG_DEBUG_TRACE);
	game->PushMsg(updateMsg);
	for (int i = 0; i < 10485; ++i)
	{
		int randNum = rand() % 10;
		if (randNum >= 8)
		{
			game->PushMsg(updateMsg);
		}else if (randNum <= 3)
		{
			MessageBase* keyMsg = new KeyboardMessage(MSG_KEY_DOWN, KEY_LEFT);
			game->PushMsg(keyMsg);
			delete keyMsg;
		}else if (randNum > 7){
			MessageBase* keyMsg = new KeyboardMessage(MSG_KEY_DOWN, KEY_UP);
			game->PushMsg(keyMsg);
			delete keyMsg;

		}else
		{
			MessageBase* keyMsg = new KeyboardMessage(MSG_KEY_DOWN, KEY_RIGHT);
			game->PushMsg(keyMsg);
			delete keyMsg;
		}

	}
	delete updateMsg;
	game->PushMsg(traceMsg);
	delete traceMsg;
	cout << "end test_random_game():\n\n";
}
int main()
{

	test_rotate();
	test_otherTetris();
	test_CreateTetrisLine();
	test_CreateTetrisSquare();
	//test_memry_leak();
	test_message();
	test_handler();
	test_state();
	test_GameFram();
	test_tetris_factory();
	test_send_msg_to_game_fram();
	test_PinToMap();
	//test_move_in_map();
	//test_ill_move();
	//test_down();
	test_random_game();
	return 0;
}