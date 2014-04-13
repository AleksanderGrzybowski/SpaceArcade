CC=g++
CFLAGS=-ggdb -std=c++11 -lsfml-window -lsfml-system -lsfml-graphics
OBJS=Bonus.o Drawable.o Enemy.o EnemyFactory.o Game.o HardEnemy.o Line.o Missile.o MissileFactory.o Moving.o NormalEnemy.o NormalMissile.o PointsCounter.o PowerMissile.o Random.o Ship.o SimpleBonus.o TextureFlipper.o main.o

all: $(OBJS)
	$(CC) $(CFLAGS) $^ -o SpaceArcade

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
