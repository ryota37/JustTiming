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

	}
}

