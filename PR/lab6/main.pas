program main;

uses GraphABC, Fractal;

var
  WINDOW_HEIGHT:= 700;
  WINDOW_WIDTH:= 1000;
  WINDOW_TITLE:= 'Кривая Гильберта';
  start: integer;
  depth: integer;
  
procedure init();
begin
  Window.CenterOnScreen;
  Window.Title := WINDOW_TITLE;
  Window.SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
end;

begin
  init;
  lastX:= 30;
  lastY:= 30;
  depth:= 7;
  start:= round((0.9 * WINDOW_HEIGHT) / (power(2, depth) - 1));
  hilbert(depth, start, 0);
end.
