unit Fractal;

interface

uses GraphABC;

var
  lastX, lastY: integer;
procedure draw(x,y: integer);
procedure hilbert(depth, x, y: integer);


implementation

procedure draw(x,y: integer);
begin
  MoveTo(lastX, lastY);
  LineTo(lastX + x, lastY + y);
  lastX:= lastX + x;
  lastY:= lastY + y;
end;

procedure hilbert(depth, x, y: integer);
begin
  if (depth > 1) then hilbert(depth - 1, y, x);
  draw(x, y);
  if (depth > 1) then hilbert(depth - 1, x, y);
  draw(y, x);
  if (depth > 1) then hilbert(depth - 1, x, y);
  draw(-x, -y);
  if (depth > 1) then hilbert(depth - 1, -y, -x);
end;

initialization
end.
