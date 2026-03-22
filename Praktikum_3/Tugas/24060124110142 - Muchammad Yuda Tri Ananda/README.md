# Tugas Praktikum 3

Nama: Muchammad Yuda Tri Ananda  
NIM: 24060124110142

## Deskripsi Tugas

Tugas pada praktikum ini adalah menambahkan telapak tangan dan jari-jari pada model lengan, lalu menyediakan kontrol keyboard agar bagian-bagian tersebut dapat digerakkan.

Hasil implementasi pada folder ini adalah program `Lengan Bergerak`, yaitu model lengan 2D/3D sederhana berbasis OpenGL GLUT yang terdiri dari:

- lengan atas
- lengan bawah
- telapak tangan
- jempol
- telunjuk
- jari tengah
- jari manis
- jari kelingking

Setiap bagian utama disusun dengan transformasi hierarkis sehingga pergerakan sendi terlihat saling terhubung.

## Hasil Program

![](./24060124110142%20-%20Muchammad%20Yuda%20Tri%20Ananda/LenganBergerak.png)

## File Terkait

- `24060124110142 - Muchammad Yuda Tri Ananda/LenganBergerak.cpp`
- `24060124110142 - Muchammad Yuda Tri Ananda/LenganBergerak`
- `24060124110142 - Muchammad Yuda Tri Ananda/LenganBergerak.png`

## Cara Kompilasi

```bash
g++ '24060124110142 - Muchammad Yuda Tri Ananda/LenganBergerak.cpp' -o '24060124110142 - Muchammad Yuda Tri Ananda/LenganBergerak' -lglut -lGLU -lGL
```

## Cara Menjalankan

```bash
./'24060124110142 - Muchammad Yuda Tri Ananda/LenganBergerak'
```

## Kontrol Keyboard

- `s` / `S`: memutar bahu
- `e` / `E`: memutar siku
- `w` / `W`: memutar pergelangan tangan
- `t` / `T`: menggerakkan ruas 1 jempol
- `u` / `U`: menggerakkan ruas 2 jempol
- `i` / `I`: menggerakkan ruas 1 telunjuk
- `o` / `O`: menggerakkan ruas 2 telunjuk
- `p` / `P`: menggerakkan ruas 3 telunjuk
- `j` / `J`: menggerakkan ruas 1 jari tengah
- `k` / `K`: menggerakkan ruas 2 jari tengah
- `l` / `L`: menggerakkan ruas 3 jari tengah
- `b` / `B`: menggerakkan ruas 1 jari manis
- `n` / `N`: menggerakkan ruas 2 jari manis
- `m` / `M`: menggerakkan ruas 3 jari manis
- `z` / `Z`: menggerakkan ruas 1 jari kelingking
- `x` / `X`: menggerakkan ruas 2 jari kelingking
- `c` / `C`: menggerakkan ruas 3 jari kelingking
- `Esc`: menutup program

## Penjelasan Implementasi

Program menggunakan pendekatan transformasi hierarkis. Artinya, ketika sendi bahu diputar maka seluruh bagian setelah bahu ikut berubah posisi. Hal yang sama berlaku untuk siku, pergelangan, dan ruas jari.

Objek digambar dengan balok wireframe menggunakan GLUT. Masing-masing ruas jari memiliki sudut sendiri sehingga dapat digerakkan secara terpisah melalui keyboard. Dengan cara ini, model tangan dapat membentuk berbagai pose sederhana sesuai input pengguna.

## Kesimpulan

Tugas ini menunjukkan penggunaan dasar OpenGL GLUT untuk membangun objek bertingkat, menerapkan translasi dan rotasi, serta menambahkan interaksi keyboard. Hasil akhirnya adalah model lengan dan tangan sederhana yang dapat digerakkan per bagian.
