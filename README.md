![Novomatic](https://github.com/Ligas10105/Collisions_internship/blob/main/images/Logo.png "Novomatic")

<h3 align="center" style="color: White; font-size: 300%" > Intensely Informative IT Internship 💻 </h3>

# Zadanie 1

Zaimplementuj funkcję `isColliding` zwracającą `true` jeśli dwa trójkąty w przestrzeni
2D kolidują ze sobą. Następnie napisz wizualizator tej kolizji. Trójkąty powinny być
widoczne na ekranie i co najmniej jeden z nich możliwy do sterowania przez
użytkownika. Kolizja powinna być w jakiś sposób zasygnalizowana użytkownikowi.

struct vec2
{
float x, y;
}
struct triangle
{
std::array<vec2, 3>points;
}
bool isColliding(const & triangle1, const & triangle2 );

