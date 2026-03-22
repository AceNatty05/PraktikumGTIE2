## Pertemuan 1
### Muchammad Yuda Tri Ananda - 24060124110142

Pertemuan ini membahas dasar grafika komputer menggunakan **OpenGL** pada bahasa **C++**. Materi berfokus pada penggambaran grafik primitif (titik, garis, segitiga, dan segiempat) untuk memahami alur render dari inisialisasi jendela sampai objek tampil di layar.

## Teori Singkat: OpenGL dan GLUT

### Apa itu OpenGL?
OpenGL (Open Graphics Library) adalah API lintas platform untuk merender grafis 2D/3D. Pada praktikum ini, OpenGL dipakai untuk menggambar objek dasar menggunakan fungsi-fungsi grafika yang sederhana.

### Apa itu GLUT?
GLUT (OpenGL Utility Toolkit) adalah library bantu untuk OpenGL agar lebih mudah:
- membuat jendela,
- mengatur mode display,
- menangani event,
- menjalankan loop utama aplikasi grafis.

Tanpa GLUT, inisialisasi windowing akan lebih kompleks karena harus berinteraksi langsung dengan sistem operasi.

### Alur Dasar Program GLUT
1. `glutInit(&argc, argv)` untuk inisialisasi GLUT.
2. `glutInitWindowSize(w, h)` untuk ukuran jendela.
3. `glutInitDisplayMode(...)` untuk mode buffer/warna.
4. `glutCreateWindow("judul")` untuk membuat jendela.
5. `glutDisplayFunc(namaFungsiRender)` untuk mendaftarkan fungsi gambar.
6. `glClearColor(r, g, b, a)` untuk warna latar belakang.
7. `glutMainLoop()` untuk menjalankan loop event dan render.

### Fungsi OpenGL yang Sering Dipakai pada Praktikum
- `glClear(GL_COLOR_BUFFER_BIT)` membersihkan buffer warna sebelum menggambar frame baru.
- `glBegin(...)` dan `glEnd()` menandai awal-akhir proses menggambar primitif.
- `glColor3f(r, g, b)` memberi warna objek.
- `glVertex3f(x, y, z)` menentukan titik koordinat objek.
- `glPointSize(...)` mengatur ukuran titik.
- `glLineWidth(...)` mengatur ketebalan garis.
- `glRectf(x1, y1, x2, y2)` menggambar segiempat terisi.
- `glFlush()` mengeksekusi perintah render pada mode single buffer.

## Penjelasan Detail per Source Code

### 1) Primitif Drawing (Jendela Dasar)
**File:** [primitif_drawing.cpp](./primitif_drawing.cpp)

#### Apa yang dibuat?
Program dasar untuk membuka jendela OpenGL dengan latar belakang biru. Program ini belum menggambar objek, tetapi menjadi pondasi semua program berikutnya.

#### Alur program
1. Inisialisasi GLUT dan ukuran jendela (`640x480`).
2. Menentukan mode tampilan `GLUT_SINGLE | GLUT_RGBA`.
3. Membuat jendela dengan judul `biru`.
4. Mendaftarkan fungsi callback `Jendela`.
5. Mengatur warna background biru menggunakan `glClearColor`.
6. Menjalankan `glutMainLoop()`.

#### Fungsi penting
- `glutDisplayFunc(Jendela)` menghubungkan event display ke fungsi render.
- `glClear(GL_COLOR_BUFFER_BIT)` membersihkan layar sebelum frame ditampilkan.
- `glFlush()` memastikan perintah gambar dikirim ke pipeline OpenGL.

#### Output
Jendela dengan background biru polos.

---

### 2) Membuat Titik
**File:** [membuat_titik.cpp](./membuat_titik.cpp)

#### Apa yang dibuat?
Program menampilkan satu titik merah pada koordinat tertentu dalam sistem koordinat OpenGL.

#### Alur program
1. Membersihkan buffer warna.
2. Mengatur ukuran titik dengan `glPointSize(5.0f)`.
3. Membuka blok gambar titik dengan `glBegin(GL_POINTS)`.
4. Mengatur warna titik merah (`glColor3f(1,0,0)`).
5. Menentukan posisi titik di `(0.25, 0.25, 0.0)`.
6. Menutup blok gambar dan mengeksekusi render.

#### Fungsi penting
- `GL_POINTS` digunakan untuk menggambar objek berbentuk titik.
- `glVertex3f` menentukan posisi titik pada koordinat normalisasi OpenGL (rentang umum -1 sampai 1).
- `glPointSize` mengatur ukuran titik agar terlihat jelas.

#### Output
Latar biru dengan satu titik merah di kuadran kanan atas.

---

### 3) Membuat Garis
**File:** [membuat_garis.cpp](./membuat_garis.cpp)

#### Apa yang dibuat?
Program menggambar satu garis putih vertikal dari titik atas ke titik bawah.

#### Alur program
1. Membersihkan layar.
2. Mengatur ketebalan garis dengan `glLineWidth(2.0f)`.
3. Memulai mode garis `glBegin(GL_LINES)`.
4. Menentukan warna garis putih.
5. Memberi dua vertex: `(0.0, 0.2, 0.0)` dan `(0.0, -0.2, 0.0)`.
6. Menutup mode gambar dan flush.

#### Fungsi penting
- `GL_LINES` menggambar garis per pasangan vertex.
- Dua pemanggilan `glVertex3f` menghasilkan satu segmen garis.
- `glLineWidth` meningkatkan visibilitas garis.

#### Output
Latar biru dengan satu garis putih vertikal di tengah sumbu X.

---

### 4) Menggambar Segitiga
**File:** [menggambar_segitiga.cpp](./menggambar_segitiga.cpp)

#### Apa yang dibuat?
Program menggambar segitiga dengan efek gradasi warna antar titik sudut (interpolasi warna).

#### Alur program
1. Membersihkan layar.
2. Memulai mode segitiga dengan `glBegin(GL_TRIANGLES)`.
3. Menetapkan warna dan vertex pertama (merah).
4. Menetapkan warna dan vertex kedua (hijau).
5. Menetapkan warna dan vertex ketiga (biru).
6. Menutup proses gambar dan flush.

#### Fungsi penting
- `GL_TRIANGLES` menggambar satu segitiga setiap tiga vertex.
- Perubahan `glColor3f` sebelum vertex membuat masing-masing sudut memiliki warna berbeda.
- OpenGL menginterpolasi warna antar sudut sehingga tampak transisi warna di dalam segitiga.

#### Output
Latar biru dengan segitiga berwarna campuran merah-hijau-biru.

---

### 5) Menggambar Segiempat Penuh
**File:** [menggambar_segiempat_penuh.cpp](./menggambar_segiempat_penuh.cpp)

#### Apa yang dibuat?
Program menggambar segiempat merah terisi (filled rectangle) menggunakan fungsi praktis `glRectf`.

#### Alur program
1. Membersihkan layar.
2. Menetapkan warna merah.
3. Menggambar segiempat dengan batas kiri-atas dan kanan-bawah (`-0.18, 0.18` ke `0.18, -0.18`).
4. Menjalankan `glFlush()`.

#### Fungsi penting
- `glRectf(x1, y1, x2, y2)` menggambar rectangle terisi tanpa perlu `glBegin/glEnd` manual.
- Nilai koordinat menentukan ukuran dan posisi objek terhadap pusat layar.

#### Output
Latar biru dengan segiempat merah terisi di area tengah.



## Tugas 

### Tugas 1
[Source Code tugas1.cpp](./tugas1.cpp)

#### Deskripsi Tugas
Membuat gambar kreatif menggunakan **hanya** dua primitif dasar: `GL_POINTS` dan `GL_LINES`.

#### Implementasi pada Program
Pada program `tugas1.cpp`, objek yang dibuat adalah wajah sederhana dengan komponen berikut:
- Outline kepala dibentuk dari banyak segmen garis (`GL_LINES`) yang menyusun bentuk lingkaran.
- Mata digambar dengan garis melingkar, kemudian pupil ditambahkan menggunakan titik (`GL_POINTS`).
- Hidung dan mulut dibuat dari beberapa segmen garis agar bentuk ekspresi terlihat jelas.
- Elemen tambahan berupa titik-titik di bagian atas sebagai aksen rambut.

#### Konsep yang Dipraktikkan
- Penggunaan pasangan vertex untuk membentuk segmen pada `GL_LINES`.
- Pemanfaatan `glPointSize(...)` agar titik tampil lebih terlihat.
- Pemecahan bentuk kompleks menjadi kumpulan garis dan titik sederhana.

#### Hasil
Program menampilkan wajah kreatif dari kombinasi titik dan garis, sesuai batasan primitif tugas.


### Tugas 2
[Source Code tugas2.cpp](./tugas2.cpp)

#### Deskripsi Tugas
Membuat program yang memanfaatkan beberapa jenis primitif OpenGL sekaligus:
`GL_LINE_STRIP`, `GL_LINE_LOOP`, `GL_TRIANGLE_FAN`, `GL_TRIANGLE_STRIP`, `GL_QUADS`, dan `GL_QUAD_STRIP`.

#### Implementasi pada Program
Pada program `tugas2.cpp`, setiap primitif divisualisasikan dalam satu scene agar mudah dibandingkan:
- `GL_LINE_STRIP`: garis sambung berurutan (polyline terbuka).
- `GL_LINE_LOOP`: garis sambung tertutup (titik akhir terhubung ke titik awal).
- `GL_TRIANGLE_FAN`: kumpulan segitiga berbagi satu titik pusat (membentuk kipas/lingkaran sederhana).
- `GL_TRIANGLE_STRIP`: deret segitiga yang efisien dengan berbagi sisi.
- `GL_QUADS`: satu bidang segiempat dari empat vertex.
- `GL_QUAD_STRIP`: deretan quad yang saling terhubung dalam pola strip.

#### Konsep yang Dipraktikkan
- Perbedaan karakter tiap mode primitif OpenGL.
- Efisiensi penyusunan vertex pada tipe *strip* dan *fan*.
- Pengaturan posisi objek per area supaya semua primitif dapat dilihat bersamaan.

#### Hasil
Program menghasilkan tampilan demonstrasi semua mode primitif yang diminta dalam satu jendela OpenGL.

## Kesimpulan
Melalui latihan ini, konsep dasar penggambaran objek primitif pada OpenGL dapat dipahami secara bertahap: mulai dari menampilkan jendela, mengatur warna, menentukan koordinat, hingga menggambar bentuk-bentuk dasar. GLUT membantu menyederhanakan proses setup sehingga fokus utama bisa diarahkan ke logika grafika.

