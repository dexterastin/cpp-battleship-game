CC = g++
CFLAGS = -std=c++14
TARGET = BattleShip
SOURSES = CBattleShipApp.cpp\
	CBattleShipMap.cpp\
	Pane.cpp\
	StatPane.cpp\
	main.cpp\
	InputPane.cpp\
	Player.cpp\
	BattleShipAIBot.cpp\
	BattleShipRndBot.cpp\
	GameManager.cpp\
	Bot.cpp\
	Ship/Ship.cpp
LDFLAGS = -lncurses

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURSES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)
