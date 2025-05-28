# include <Siv3D.hpp> // Siv3D v0.6.15

bool isCursorStop = false;

void cursorUpdate(Rect& cursor)
{
	const double sin = Periodic::Triangle1_1(2s);
	if (!isCursorStop)
	{
		cursor.x = 400 * sin + 400;
	}
	cursor.draw(Palette::Black);
}

void cursorStop()
{
	if (KeyEnter.down())
	{
		isCursorStop = !isCursorStop;
		// Need to stop the timer of Periodic::Triangle1_1
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

void score(Rect& cursor)
{
	if (!isCursorStop) return;
	CursorOverColor color = getCursorOverColorType(cursor);
	if (color == CursorOverColor::Red) Print << U"Red";
	if (color == CursorOverColor::Yellow) Print << U"Yellow";
	if (color == CursorOverColor::Green) Print << U"Green";
	if (color == CursorOverColor::Gray) Print << U"Gray";
}

void Main()
{
	Scene::SetBackground(ColorF{Palette::Gray});
	Rect cursor = Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 20, 50 };


	while (System::Update())
	{
		Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 600, 50 }.draw(Palette::Green);
		Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 300, 50 }.draw(Palette::Yellow);
		Rect{ Arg::center(Scene::Center().x, Scene::Center().y), 50, 50 }.draw(Palette::Red);

		cursorUpdate(cursor);
		cursorStop();
		score(cursor);

	}
}

