#ifndef __geom_h
#define __geom_h

typedef struct _Point {
    int x;
    int y;
} Point;

#define POINT_SET(pt, nx, ny) (pt).x = (nx), (pt).y = (ny)

typedef struct _Size {
    int width;
    int height;
} Size;

#define SIZE_SET(sz, w, h) (sz).width = (w), (sz).height = (h)

typedef struct _Rect {
    int x;
    int y;
    int width;
    int height;
} Rect;

#define RECT_SET_POINT(r, nx, ny) \
    (r).x = (ny), (r).y = (ny)
#define RECT_SET_SIZE(r, w, h) \
    (r).width = (w), (r).height = (h)
#define RECT_SET(r, nx, ny, w, h) \
    (r).x = (nx), (r).y = (ny), (r).width = (w), (r).height = (h)

#define RECT_EQUAL(r1, r2) ((r1).x == (r2).x && (r1).y == (r2).y && \
			    (r1).width == (r2).width && \
                            (r1).height == (r2).height)

#define RECT_CONTAINS(r, x, y) \
    ((x) >= (r).x && (x) < (r).x + (r).width && \
     (y) >= (r).y && (y) < (r).y + (r).height)
#define RECT_CONTAINS_RECT(r, o) \
    ((o).x >= (r).x && (o).x + (o).width <= (r).x + (r).width && \
     (o).y >= (r).y && (o).y + (o).height <= (r).y + (r).height)
#define RECT_INTERSECTS_RECT(r, o) \
    ((o).x < (r).x + (r).width && (o).x + (o).width > (r).x && \
     (o).y < (r).y + (r).height && (o).y + (o).height > (r).y)

typedef struct _Strut {
    int left;
    int top;
    int right;
    int bottom;
} Strut;

typedef struct _StrutPartial {
    int left;
    int top;
    int right;
    int bottom;

    int left_start,   left_end;
    int top_start,    top_end;
    int right_start,  right_end;
    int bottom_start, bottom_end;
} StrutPartial;

#define STRUT_SET(s, l, t, r, b) \
    (s).left = (l), (s).top = (t), (s).right = (r), (s).bottom = (b)

#define STRUT_PARTIAL_SET(s, l, t, r, b, ls, le, ts, te, rs, re, bs, be) \
    (s).left = (l), (s).top = (t), (s).right = (r), (s).bottom = (b), \
    (s).left_start = (ls), (s).left_end = (le), \
    (s).top_start = (ts), (s).top_end = (te), \
    (s).right_start = (rs), (s).right_end = (re), \
    (s).bottom_start = (bs), (s).bottom_end = (be)

#define STRUT_ADD(s1, s2) \
    (s1).left = MAX((s1).left, (s2).left), \
    (s1).right = MAX((s1).right, (s2).right), \
    (s1).top = MAX((s1).top, (s2).top), \
    (s1).bottom = MAX((s1).bottom, (s2).bottom)

#define STRUT_EQUAL(s1, s2) \
    ((s1).left == (s2).left && \
     (s1).top == (s2).top && \
     (s1).right == (s2).right && \
     (s1).bottom == (s2).bottom && \
     (s1).left_start == (s2).left_start && \
     (s1).left_end == (s2).left_end && \
     (s1).top_start == (s2).top_start && \
     (s1).top_end == (s2).top_end && \
     (s1).right_start == (s2).right_start && \
     (s1).right_end == (s2).right_end && \
     (s1).bottom_start == (s2).bottom_start && \
     (s1).bottom_end == (s2).bottom_end)

#endif
