# include <Siv3D.hpp> // Siv3D v0.6.15

void cursorUpdate(Rect& cursor)
{
	cursor.x += Scene::DeltaTime() * 100;
	cursor.draw(Palette::Black);
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
	}
}

