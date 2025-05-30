# include <Siv3D.hpp> // Siv3D v0.6.15

# include <cmath>

void cursorUpdate(Rect& cursor, bool isCursorStop, double periodicValue)
{
	if (!isCursorStop)
	{
		cursor.x = 400 * periodicValue + 400;
	}
	cursor.draw(Palette::Black);
}

void cursorStop(bool& isCursorStop)
{
	if (KeyEnter.down())
	{
		isCursorStop = !isCursorStop;
	}
}

enum class CursorOverColor
{
	Red,
	Yellow,
	Green,
	Gray
};

CursorOverColor getCursorOverColorType(Rect& cursor)
{
	if (375 <= cursor.x && cursor.x <= 425) return CursorOverColor::Red;
	if (250 <= cursor.x && cursor.x <= 550) return CursorOverColor::Yellow;
	if (100 <= cursor.x && cursor.x <= 700) return CursorOverColor::Green;
	return CursorOverColor::Gray;
}

void score(Rect& cursor, bool isCursorStop)
{
	if (!isCursorStop) return;
	CursorOverColor color = getCursorOverColorType(cursor);
	if (color == CursorOverColor::Red) Print << U"Red";
	if (color == CursorOverColor::Yellow) Print << U"Yellow";
	if (color == CursorOverColor::Green) Print << U"Green";
	if (color == CursorOverColor::Gray) Print << U"Gray";
}

void restart(bool& isCursorStop, Rect& cursor, double& periodicValue)
{
	if (KeySpace.pressed())
	{
		isCursorStop = false;
		cursor = Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 20, 50 };
		periodicValue = 0.0;
	}
}

double generatePeriodicValue(bool& CursorStop, double& angle_rad)
{
	if (!CursorStop)
	{
		angle_rad += Scene::DeltaTime();
	}
	return sin(angle_rad);
}

void Main()
{
	bool isCursorStop = false;
	Scene::SetBackground(ColorF{Palette::Gray});
	Rect cursor = Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 20, 50 };
	double angle_rad = 0.0;

	while (System::Update())
	{
		double periodicValue = generatePeriodicValue(isCursorStop, angle_rad);

		Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 600, 50 }.draw(Palette::Green);
		Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 300, 50 }.draw(Palette::Yellow);
		Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 50, 50 }.draw(Palette::Red);

		cursorUpdate(cursor, isCursorStop, periodicValue);
		cursorStop(isCursorStop);
		score(cursor, isCursorStop);
		restart(isCursorStop, cursor, periodicValue);
	}
}

