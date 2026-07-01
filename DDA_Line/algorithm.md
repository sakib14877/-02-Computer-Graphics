
# DDA Algorithm

## Formula

dx = x2 - x1

dy = y2 - y1

steps = max(abs(dx), abs(dy))

Xinc = dx / steps

Yinc = dy / steps

## Algorithm

1. Input two endpoints.
2. Compute dx and dy.
3. Determine the number of steps.
4. Compute X increment.
5. Compute Y increment.
6. Plot the first point.
7. Repeat:
   - x = x + Xinc
   - y = y + Yinc
8. Plot until all steps are completed.
