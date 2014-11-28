// SRM 441 div2 500.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class PaperAndPaintEasy
{
public:
    long computeArea(int width, int height, int xfold, int count, int x1, int y1, int x2, int y2)
    {
        if (xfold > width/2)
            xfold = width - xfold;
        x1 = x1 + xfold;
        x2 = x2 + xfold;
        long vertical_folds = count+1;
 /*       if (count > 0)
            vertical_folds = height/count;
        else
            vertical_folds = 1;
  */      long no_of_squares_paint = (y2-y1)*(x2-x1);
        long vertical_unfold_painted = vertical_folds*no_of_squares_paint;
        long xfold_covered_init = (y2-y1)*((2*xfold) - x1);
        if (xfold_covered_init < 0)
            xfold_covered_init = 0;
        long xfold_total = xfold_covered_init*vertical_folds;
        cout << "xfold is " << xfold << endl;
        cout << "vertical folds is " << vertical_folds << endl;
        cout << "no_of_squares_paint is " << no_of_squares_paint << endl;
        cout << "vertical_unfold_painted " << vertical_unfold_painted << endl;
        cout << "xfold_covered_init " << xfold_covered_init << endl;
        cout << "xfold_total " << xfold_total << endl;
        return width*height - (xfold_total + vertical_unfold_painted);
    }
};

int main()
{
PaperAndPaintEasy a;
cout << "Final answer is " << a.computeArea(4,8,4,3,0,1,2,2);
return 0;
}
