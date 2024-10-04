#include <uinfo.h>
#include <keyboard.h>
#include <string.h>
#include <idt.h>

char *get_username()
{

}
void request_username()
{
    irq_install_handler(1, &user_require);
}