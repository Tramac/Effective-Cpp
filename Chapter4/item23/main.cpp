#include "head.h"

using namespace WebBrowserStuff;

// -----Demo 1.non-member函数-----
void clearBrowser(WebBrowser& wb) {
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

int main()
{
    WebBrowser wb;
    clearBrowser(wb);
    
    return 0;
}
