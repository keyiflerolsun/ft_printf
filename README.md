# ft_printf

Bu proje, C dilinde standart `printf` fonksiyonunun temel işlevlerini taklit eden bir kütüphanedir. Proje, *École 42* kapsamında geliştirilmiştir.

## Özellikler

- `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p` formatlarını destekler.
- Hatalı veya eksik formatlarda güvenli davranış.
- Kendi başına çalışan bir kütüphane olarak kullanılabilir.

## Kurulum

Projeyi derlemek için terminalde aşağıdaki komutu çalıştırın:

```sh
make
```

Başarılı derlemeden sonra `libftprintf.a` dosyası oluşacaktır.

## Kullanım

Kendi projenize eklemek için:

1. `ft_printf.h` dosyasını projenize dahil edin.
2. Derlerken `libftprintf.a` kütüphanesini ekleyin.

Örnek kullanım:

```c
#include "ft_printf.h"

int    main(void)
{
    ft_printf("Hey, this is %s %d!\n", "École", 42);
    return (0);
}
```

## Temizlik

Derlenmiş dosyaları temizlemek için:

```sh
make clean
```

Kütüphaneyi ve objeleri tamamen silmek için:

```sh
make fclean
```
