
struct point /* структура и её имя (tag) */
{
  int x; /* переменные структуры */
  int y;
};

struct {...} x, y, z; /* объявляет переменные x, y, z  такого же типа как и структура (в данном случае int x, y, z;) */

struct point; /* такое объявление структуры не резервирует память, но если она имеет имя(тэг), то можно по нему определять структурные объекты */
struct point pt; /* определили структурный элемент (в данному случаем переменную) с типом struct point */

/*обращение к элементам структуры осуществляется при помощи "." */
printf("%d, %d", pt.x, pt.y); /* печатает координаты точки pt по x и y */

/* структура может иметь внутри себя другие сруктуры */
struct rect /* структура описывающая прямоугольник */
{
  struct point pt1; /* точка pt1 */
  struct point pt2; /* точка pt2 */
};
/* создадим элемент структуры */
struct rect screen;
/* то можно получить координаты точек pt1 и pt2 подобным образом */
screen.pt1.x;

/* взаимодействие функций и структур */
/* makepoint: создает точку по x и y */
struct point makepoint(int x, int y)
{
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
}

/* теперь при помощи makepoint можно выполнять динамическую инициализаю любой структуры или формировать структурные аргументы для ф-й */
struct rect screen; /* создали элемент структуры rect с именем screen */
struct point middle; /* создали элемент струкруты point с именем middle */
struct point makepoint(int, int); /* описали ф-ю для динамического создания структурных элементов point */

screen.pt1 = makepoint(0, 0); /* первая точка */
screen.pt2 = makepoint(XMAX, YMAX); /* вторая точка */ 
middle = ((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2); /* средняя точка */

/* ф-ии для манипуляций с точками */
/* addpoint: сложение 2-х точек */
struct point addpoint(struct point p1, struct point p2) /* данная ф-я принимает на вход и выводит - структуры */
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

/* ptinrect: проверяет находится ли точка внутри rect, в котором его левая и нижнии стороны ему принадлежат, а верх и право - не принадлежат */
/* printrec: возвращает 1, если p в r, 0 - если нет */
int printrec(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* сл функция гарантирует получение прямоугольника в каноническом виде */
/* canonrect: канонизация координат прямоугольника */
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct rect canonrect(struct rect r)
{
  struct rect temp;
  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}

// структуры можно передавать ф-уями не целиком а через указатель
struct point *pp; // pp - указатель на структуру типа struct point, т.е. pp указывает на структуру point а *pp - это сама структура, а (*pp).x - её элементы
struct point origin, *pp;
pp = &origin;
printf("origin: (%d, %d)\n", (*pp).x, (*pp).y);

// т.к. указаели на элементы структур используются очень часто, то придумали для быстрого доступа к ним следующий оператор ->
printf("origin: (%d, %d)\n", pp->x, pp->y);

// следующие выражения эквивалентны
struct rect r, *rp = &r;
r.pt1.x;
rp->pt1.x;
(r.pt1).x;
(rp->pt1).x;

