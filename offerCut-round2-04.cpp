#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Vedge {
    int x, y1, y2;
};

struct Hedge {
    int y, x1, x2;
};

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        vector<Vedge> vleft, vright;
        vector<Hedge> htop, hbot;

        int N, M;
        cin >> N >> M;
        int lastX, lastY;
        cin >> lastX >> lastY;
        int initX = lastX, initY = lastY;
        for (int i= 1; i < N; ++i) {
            int X, Y;
            cin >> X >> Y;


            if (X == lastX && Y == lastY) {
                Vedge ev;
                ev.x = X;
                ev.y1 = Y;
                ev.y2 = Y;
                vleft.push_back(ev);
                vright.push_back(ev);

                Hedge eh;
                eh.y = Y;
                eh.x1 = X;
                eh.x2 = X;
                htop.push_back(eh);
                hbot.push_back(eh);
                continue;
            }
            if (X == lastX) {
                //vertical edge
                if (Y > lastY) {
                    //left edge
                    Vedge e;
                    e.x = X;
                    e.y1 = lastY;
                    e.y2 = Y;
                    vleft.push_back(e);
                } else {
                     Vedge e;
                     e.x = X;
                     e.y1 = Y;
                     e.y2 = lastY;
                     vright.push_back(e);
                }
                lastY = Y;
            } else {
                //horizontal edge
                if (X > lastX) {
                     // top edge
                     Hedge e;
                     e.y = Y;
                     e.x1 = lastX;
                     e.x2 = X;
                     htop.push_back(e);
                } else {
                     Hedge e;
                     e.y = Y;
                     e.x1 = X;
                     e.x2 = lastX;
                     hbot.push_back(e);
                }
                lastX = X;
            }
        }

        if (lastX != initX) {
             //horizon
            Hedge e;
            e.y = lastY;
            if (initX > lastX) {
                e.x1 = lastX;
                e.x2 = initX;
                htop.push_back(e);
            } else {
                e.x1 = initX;
                e.x2 = lastX;
                hbot.push_back(e);
            }
        } else if (lastY != initY) {
            Vedge e;
            e.x = lastX;
            if (lastY < initY) {
                e.y1 = lastY;
                e.y2 = initY;
                vleft.push_back(e);
            } else {
                e.y1 = initY;
                e.y2 = lastY;
                vright.push_back(e);
            }
        }


        int ans = INT_MAX;
        for (auto e1 : vleft) {
            for (auto e2 : vright) {
                if (e1.y1 >= e2.y2 || e1.y2 <= e2.y1) {
                    int cur = e2.x-e1.x;
                    if (cur <= 0) continue;
                    if (e1.y1 >= e2.y2) cur = max(cur, e1.y1-e2.y2);
                    else cur = max(cur, e2.y1-e1.y2);
                    ans = min(ans, cur);
                }
                else {
                    if (e2.x > e1.x) {
                        ans = min(ans, e2.x-e1.x);
                    }
                }
            }
        }
        for (auto e1 : htop) {
            for (auto e2 : hbot) {
                if (e1.x1 >= e2.x2 || e1.x2 <= e2.x1) {
                    int cur = e1.y-e2.y;
                    if (cur <= 0) continue;
                    if (e1.x1 >= e2.x2) cur = max(cur, e1.x1-e2.x2);
                    else cur = max(cur, e2.x1-e1.x2);
                    ans = min(cur, ans);
                }
                else {
                    if (e1.y > e2.y) {
                        ans = min(ans, e1.y-e2.y);
                    }
                }
            }
        }

        if (ans < M) {
             cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
