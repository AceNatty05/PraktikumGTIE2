# Keaktifan Praktikum 3

Nama: Muhammad Farhan Abdul Azis  
NIM: 24060124140166

## Jawaban Teori

### 1. Fungsi `glutReshapeFunc` dan `glutPostRedisplay`

`glutReshapeFunc` digunakan untuk mendaftarkan callback yang akan dijalankan saat ukuran window berubah. Fungsi ini penting agar `viewport`, proyeksi, dan rasio tampilan tetap sesuai ketika jendela diperbesar atau diperkecil.

`glutPostRedisplay` digunakan untuk memberi tahu GLUT bahwa window perlu digambar ulang. Biasanya fungsi ini dipanggil setelah ada perubahan data, misalnya sudut rotasi objek berubah karena input keyboard.

### 2. Tugas prosedur `idle` pada animasi kubus bergerak

Prosedur `idle` dipakai untuk menjalankan proses yang terus diulang ketika program sedang tidak menangani input lain. Pada animasi kubus bergerak, fungsi ini biasanya dipakai untuk memperbarui posisi, rotasi, atau status objek secara terus-menerus sehingga animasi terlihat hidup.

### 3. Pengertian proyeksi, `projection`, dan `modelview`

Proyeksi adalah cara objek 3D ditampilkan ke layar 2D. Dalam OpenGL klasik:

- `GL_PROJECTION` dipakai untuk mengatur cara kamera melihat objek, misalnya dengan perspektif atau ortho.
- `GL_MODELVIEW` dipakai untuk transformasi model dan pandangan, seperti translasi, rotasi, dan skala objek di dalam scene.

Sederhananya, `projection` mengatur bagaimana scene dilihat, sedangkan `modelview` mengatur posisi dan bentuk objek di scene.

## Program 1: Telunjuk Naik

Program ini menampilkan lengan, telapak tangan, dan lima jari berbentuk wireframe. Pose awalnya membentuk gestur telunjuk naik, dengan telunjuk terbuka dan jari lain menekuk.

![](./24060124140166_Muhammad%20Farhan%20Abdul%20Azis/TelunjukNaik.png)

### File Terkait

- `24060124140166_Muhammad Farhan Abdul Azis/TelunjukNaik.cpp`
- `24060124140166_Muhammad Farhan Abdul Azis/TelunjukNaik`
- `24060124140166_Muhammad Farhan Abdul Azis/TelunjukNaik.png`

### Cara Kompilasi

```bash
g++ '24060124140166_Muhammad Farhan Abdul Azis/TelunjukNaik.cpp' -o '24060124140166_Muhammad Farhan Abdul Azis/TelunjukNaik' -lglut -lGLU -lGL
```

### Cara Menjalankan

```bash
./'24060124140166_Muhammad Farhan Abdul Azis/TelunjukNaik'
```

### Kontrol Keyboard

- `s` / `S`: putar bahu
- `e` / `E`: putar siku
- `w` / `W`: putar pergelangan
- `t` / `T`: ruas 1 jempol
- `u` / `U`: ruas 2 jempol
- `i` / `I`: ruas 1 telunjuk
- `o` / `O`: ruas 2 telunjuk
- `p` / `P`: ruas 3 telunjuk
- `j` / `J`: ruas 1 jari tengah
- `k` / `K`: ruas 2 jari tengah
- `l` / `L`: ruas 3 jari tengah
- `b` / `B`: ruas 1 jari manis
- `n` / `N`: ruas 2 jari manis
- `m` / `M`: ruas 3 jari manis
- `z` / `Z`: ruas 1 kelingking
- `x` / `X`: ruas 2 kelingking
- `c` / `C`: ruas 3 kelingking
- `Esc`: keluar dari program

## Program 2: Peace Sign

Program ini menampilkan model tangan dengan pose awal membentuk tanda damai atau `peace sign`. Jari telunjuk dan jari tengah dibuat terbuka, sedangkan jari lain ditekuk sehingga membentuk pose yang sesuai.

![](./24060124140166_Muhammad%20Farhan%20Abdul%20Azis/PeaceSign.png)

### File Terkait

- `24060124140166_Muhammad Farhan Abdul Azis/PeaceSign.cpp`
- `24060124140166_Muhammad Farhan Abdul Azis/PeaceSign`
- `24060124140166_Muhammad Farhan Abdul Azis/PeaceSign.png`

### Cara Kompilasi

```bash
g++ '24060124140166_Muhammad Farhan Abdul Azis/PeaceSign.cpp' -o '24060124140166_Muhammad Farhan Abdul Azis/PeaceSign' -lglut -lGLU -lGL
```

### Cara Menjalankan

```bash
./'24060124140166_Muhammad Farhan Abdul Azis/PeaceSign'
```

### Penjelasan Singkat Implementasi

Program dibuat dengan transformasi hierarkis menggunakan `glPushMatrix`, `glPopMatrix`, `glTranslatef`, dan `glRotatef`. Lengan atas, lengan bawah, telapak, dan jari-jari digambar sebagai balok wireframe. Setiap jari memiliki beberapa ruas dengan sudut awal tertentu sehingga pose akhir dapat membentuk gestur yang diinginkan.
