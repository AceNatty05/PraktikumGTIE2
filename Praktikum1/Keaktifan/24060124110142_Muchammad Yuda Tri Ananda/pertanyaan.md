## Jawaban Pertanyaan MODUL 1
### MUCHAMMAD YUDA TRI ANANDA 24060124110142

### 1) Apa fungsi `glColor3f(1.0f, 0.0f, 0.0f)` dan apa fungsi “f”?

* `glColor3f(r, g, b)` itu digunain buat mengatur **warna saat ini** (current color) untuk vertex yang akan digambar **setelah** pemanggilan fungsi ini.
* Nilai `r, g, b` adalah **RGB** dengan rentang **0.0 sampai 1.0**:

  * `1.0f, 0.0f, 0.0f` = **merah penuh**
* Huruf **`f`** artinya parameter bertipe **float** (bukan int/double).

jadi kayak **Warna hijau** pakai:

```cpp
glColor3f(0.0f, 1.0f, 0.0f);
```

---

### 2) Apakah ada `glColor4f`? Kalau ada, untuk apa?

Ada `glColor4f(r, g, b, a)` menambahkan **alpha** (`a`) untuk transparansi.

* `a = 1.0` → opak (tidak transparan)
* `a = 0.0` → transparan penuh

Contoh:

```cpp
glColor4f(0.0f, 1.0f, 0.0f, 0.5f); // hijau transparan 50%
```

>  supaya transparansi terlihat, biasanya perlu blending:

```cpp
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
```

---

### 3) Apa fungsi `glVertex3f(-0.10, -0.10, 0.00)`?

`glVertex3f(x, y, z)` mendefinisikan **titik/vertex** dalam koordinat 3D untuk primitive yang sedang digambar (di antara `glBegin(...)` dan `glEnd()`).

Nilai negatif artinya posisinya **di kiri** (x negatif) atau **di bawah** (y negatif) terhadap titik origin (0,0,0).
Pada mode normal OpenGL (tanpa matrix aneh), area tampilan default (NDC setelah transformasi) umumnya terlihat di kisaran **-1 s/d 1**

---

### 4) Apa fungsi `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA)`?

Mengatur mode buffer tampilan GLUT

* `GLUT_SINGLE` → **single buffering** (gambar langsung ke layar; bisa flicker)
* `GLUT_RGBA` → pakai **color mode RGBA** (bukan color index)

Biasanya untuk animasi lebih halus dipakai:

```cpp
GLUT_DOUBLE | GLUT_RGBA
```

lalu di akhir render pakai `glutSwapBuffers()`.

