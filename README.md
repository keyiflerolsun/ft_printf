# ft_printf

Bu proje, C dilinde standart `printf` fonksiyonunun temel işlevlerini taklit eden bir kütüphanedir. Proje, *École 42* kapsamında geliştirilmiştir.

## Özellikler

- `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p` formatlarını destekler.
- Hatalı veya eksik formatlarda güvenli davranış.
- Kendi başına çalışan bir kütüphane olarak kullanılabilir.

## Dosya Yapısı

- `srcs/` — Kaynak dosyalar (`ft_printf.c`, `ft_char.c`, `ft_num.c`)
- `includes/` — Başlık dosyası (`ft_printf.h`)
- `obj/` — Derlenmiş nesne dosyaları
- `libftprintf.a` — Oluşan statik kütüphane
- `Makefile` — Derleme talimatları

## Kurulum

Projeyi derlemek için terminalde aşağıdaki komutu çalıştırın:

```sh
make
```

Başarılı derlemeden sonra `libftprintf.a` dosyası oluşacaktır.

## Kullanım

Kendi projenize eklemek için:

1. `includes/ft_printf.h` dosyasını projenize dahil edin.
2. Derlerken `libftprintf.a` kütüphanesini ekleyin.

Örnek kullanım:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Merhaba %s! Sayı: %d\n", "Dünya", 42);
    return 0;
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
