CC=g++
CFLAGS=-ggdb -std=c++11 -lsfml-window -lsfml-system -lsfml-graphics
OBJS= Bonus.o Drawable.o Enemy.o EnemyFactory.o fileExists.o FileNotFoundException.o Game.o GameOverText.o HardEnemy.o Line.o main.o Missile.o MissileFactory.o Moving.o NormalEnemy.o NormalMissile.o PointsCounter.o PowerMissile.o PowerMissileIndicator.o Random.o Ship.o SimpleBonus.o TextObject.o TextureFlipper.o

all: $(OBJS)
	$(CC) $(CFLAGS) $^ -o SpaceArcade

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
