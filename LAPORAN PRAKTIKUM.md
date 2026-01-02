# MODUL 12 & 13
# Pengurutan Data
___
Rahmat Ahdaf Albariza (103112430003)
___
# Dasar Teori
Terdapat dua metode pengurutan data, yaitu Selection Sort dan Insertion Sort. Pada Selection Sort, ide utamanya adalah mencari nilai ekstrim dari kumpulan data dan menukarnya dengan posisi yang tepat, dimulai dari data yang paling kiri, lalu proses ini diulang hingga seluruh data terurut. Sementara itu, Insertion Sort bekerja dengan menyisipkan setiap elemen ke dalam posisi yang sesuai dalam bagian data yang sudah terurut, dengan cara menggeser elemen yang lebih besar ke kanan untuk memberi ruang. Kedua algoritma ini digunakan untuk mengurutkan array satu dimensi secara in-place, dengan Selection Sort lebih efisien pada data berukuran kecil karena jumlah penukaran yang sedikit, sedangkan Insertion Sort lebih cepat digunakan pada data yang hampir terurut karena memiliki performa yang lebih baik dalam kondisi tersebut.
___

# Guided
___
#### **nomor 1**
>Diberikan `n` bilangan bulat positif. Buat program untuk mengurutkan angka ganjil secara membesar (ascending) dan angka genap secara mengecil (descending), lalu gabungkan hasilnya dengan ganjil duluan. Gunakan selection sort dalam proses pengurutan.

```go
package main

import "fmt"

func selectionSortAsc(arr []int, panjang int) {
	var temp, i, j, idxMin int
	for i = 0; i < panjang-1; i++ {
		idxMin = i
		for j = i + 1; j < panjang; j++ {
			if arr[j] < arr[idxMin] {
				idxMin = j
			}
		}
		temp = arr[idxMin]
		arr[idxMin] = arr[i]
		arr[i] = temp
	}
}

func selectionSortDesc(arr []int, panjang int) {
	var temp, i, j, idxMax int
	for i = 0; i < panjang-1; i++ {
		idxMax = i
		for j = i + 1; j < panjang; j++ {
			if arr[j] > arr[idxMax] {
				idxMax = j
			}
		}
		temp = arr[idxMax]
		arr[idxMax] = arr[i]
		arr[i] = temp
	}
}

func main() {
	n := 10
	numbers := []int{12, 7, 3, 2, 9, 6, 8, 1, 11, 4}

	var ganjil []int
	var genap []int

	for i := 0; i < n; i++ {
		if numbers[i]%2 == 1 {
			ganjil = append(ganjil, numbers[i])
		} else {
			genap = append(genap, numbers[i])
		}
	}

	selectionSortAsc(ganjil, len(ganjil))
	selectionSortDesc(genap, len(genap))

	for i := 0; i < len(ganjil); i++ {
		fmt.Print(ganjil[i], " ")
	}
	for i := 0; i < len(genap); i++ {
		fmt.Print(genap[i], " ")
	}
}
```
Output:

>![](output/G1.PNG)

Penjelasan:
Program ini dimulai dengan mendefinisikan sebuah array berisi angka yang akan diproses. Fungsi sorting kemudian dipanggil untuk memisahkan angka ganjil dan genap dalam array tersebut. Angka ganjil disimpan dalam array `ganjil` dan angka genap dalam array `genap`. Selanjutnya, setiap array akan diurutkan secara terpisah: array `ganjil` diurutkan secara menaik menggunakan fungsi `selectionSortAsc`, sementara array `genap` diurutkan secara menurun menggunakan fungsi `selectionSortDesc`. Setelah kedua array terurut, keduanya digabungkan secara logika dalam proses output, dengan angka ganjil ditampilkan terlebih dahulu diikuti oleh angka genap. Hasil akhirnya adalah array yang telah terurut sesuai dengan aturan yang telah ditentukan, dan program menampilkan hasil array yang sudah diurutkan tersebut.
___
#### **nomor 2**
>Sebuah kelas memiliki sejumlah siswa yang telah mengikuti ujian. Tugas Anda adalah membuat program yang membaca nilai-nilai ujian siswa dengan struct berisikan `nim` dan `nilai`, lalu mengurutkannya dari yang tertinggi ke yang terendah menggunakan insertion sort.

```go
package main

import "fmt"

type identitas struct {
	nim  string
	nilai int
}

func nilaiujian(arr []identitas) {
	var temp identitas
	for i := 1; i < len(arr); i++ {
		temp = arr[i]
		j := i

		for j > 0 && temp.nilai > arr[j-1].nilai {
			arr[j] = arr[j-1]
			j--
		}

		arr[j] = temp
	}
}

func main() {
	orang := []identitas{
		{"101", 75},
		{"102", 90},
		{"103", 85},
		{"104", 95},
		{"105", 80},
	}

	nilaiujian(orang)

	for i := 0; i < len(orang); i++ {
		fmt.Println(orang[i].nama, ": ", orang[i].nilai)
	}
}
```
Output:

>![](output/G2.PNG)

Penjelasan:
**Program ini dimulai dengan mendefinisikan sebuah array berisi angka yang akan diproses.** Namun, dalam kasus ini bukan angka saja, melainkan data berupa struct `identitas` yang menyimpan NIM dan nilai ujian setiap orang. Fungsi sorting kemudian dipanggil untuk mengurutkan data berdasarkan nilai ujian secara menurun menggunakan metode _insertion sort_.
Setiap elemen dalam array dibandingkan satu per satu dan dipindahkan ke posisi yang sesuai agar urut dari nilai terbesar ke nilai terkecil. Setelah array `orang` terurut, program menampilkan hasil data yang telah diurutkan tersebut, di mana setiap baris menunjukkan NIM dan nilai dari masing-masing individu.
Hasil akhirnya adalah daftar data yang telah disusun dari nilai tertinggi ke nilai terendah, dan program mencetak daftar tersebut ke layar.

___


# Unguided
___
# A. Selection Short
___
#### **nomor 1**
>Hercules, preman terkenal seantero ibukota, memiliki kerabat di banyak daerah. Tentunya Hercules sangat suka mengunjungi semua kerabatnya itu. Diberikan masukan nomor rumah dari semua kerabatnya di suatu daerah, buatlah program rumahkerabat yang akan menyusun nomor-nomor rumah kerabatnya secara terurut membesar menggunakan algoritma selection sort.
>
>Masukan : dimulai dengan sebuah integer 𝒏 (0 < n < 1000), banyaknya daerah kerabat Hercules tinggal. Isi 𝒏 baris berikutnya selalu dimulai dengan sebuah integer 𝒎 (0 < m < 1000000) yang menyatakan banyaknya rumah kerabat di daerah tersebut, diikuti dengan rangkaian bilangan bulat positif, nomor rumah para kerabat.
>
>Keluaran : terdiri dari n baris, yaitu rangkaian rumah kerabatnya terurut membesar di masingmasing daerah.

```go
package main

import (
	"fmt"
)

func selectionSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}
		// Tukar elemen
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	}
}

func main() {
	var n int
	fmt.Scan(&n) // jumlah daerah

	allData := make([][]int, n)

	// Ambil semua input terlebih dahulu
	for i := 0; i < n; i++ {
		var m int
		fmt.Scan(&m)

		houses := make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&houses[j])
		}
		allData[i] = houses
	}

	// Proses dan keluarkan output setelah semua input selesai
	for i := 0; i < n; i++ {
		selectionSort(allData[i])
		for j, val := range allData[i] {
			fmt.Print(val)
			if j != len(allData[i])-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
```
Output:

>![](output/Uss1.PNG)

Penjelasan:
**Program ini dimulai dengan mendefinisikan sebuah array berisi angka yang akan diproses.** Dalam hal ini, array dua dimensi digunakan untuk menyimpan data beberapa daerah, di mana setiap daerah memiliki sejumlah rumah dengan nilai tertentu. Fungsi sorting kemudian dipanggil untuk mengurutkan data pada setiap daerah secara terpisah.
Program membaca terlebih dahulu semua data input: jumlah daerah, jumlah rumah di setiap daerah, serta nilai-nilai rumah tersebut. Setelah semua data dimasukkan, masing-masing array (yang mewakili satu daerah) akan diurutkan secara menaik menggunakan algoritma _Selection Sort_.
Setelah setiap array terurut, program mencetak hasil pengurutan tersebut ke layar, satu baris per daerah. Hasil akhirnya adalah tampilan data setiap daerah yang telah diurutkan dari nilai terkecil ke terbesar, ditampilkan setelah semua input selesai diproses.
___
#### **nomor 2**
>Belakangan diketahui ternyata Hercules itu tidak berani menyeberang jalan, maka selalu diusahakan agar hanya menyeberang jalan sesedikit mungkin, hanya diujung jalan. Karena nomor rumah sisi kiri jalan selalu ganjil dan sisi kanan jalan selalu genap, maka buatlah program kerabat dekat yang akan menampilkan nomor rumah mulai dari nomor yang ganjil lebih dulu terurut membesar dan kemudian menampilkan nomor rumah dengan nomor genap terurut mengecil.
>
>Format Masukan : masih persis sama seperti sebelumnya.
>
>Keluaran : terdiri dari n baris, yaitu rangkaian rumah kerabatnya terurut membesar untuk nomor ganjil, diikuti dengan terurut mengecil untuk nomor genap, di masing-masing daerah.

```go
package main

import (
	"fmt"
)

func selectionSortAscending(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	}
}

func selectionSortDescending(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		maxIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] > arr[maxIdx] {
				maxIdx = j
			}
		}
		arr[i], arr[maxIdx] = arr[maxIdx], arr[i]
	}
}

func main() {
	var n int
	fmt.Scan(&n) // Jumlah daerah

	allGanjil := make([][]int, n)
	allGenap := make([][]int, n)

	// Ambil semua input, pisahkan ganjil dan genap
	for i := 0; i < n; i++ {
		var m int
		fmt.Scan(&m)
		ganjil := []int{}
		genap := []int{}
		for j := 0; j < m; j++ {
			var num int
			fmt.Scan(&num)
			if num%2 == 0 {
				genap = append(genap, num)
			} else {
				ganjil = append(ganjil, num)
			}
		}
		allGanjil[i] = ganjil
		allGenap[i] = genap
	}

	// Proses dan cetak hasil
	for i := 0; i < n; i++ {
		selectionSortAscending(allGanjil[i])
		selectionSortDescending(allGenap[i])

		for _, val := range allGanjil[i] {
			fmt.Print(val, " ")
		}
		for j, val := range allGenap[i] {
			fmt.Print(val)
			if j != len(allGenap[i])-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
```
Output:

>![](output/Uss2.PNG)

Penjelasan:
**Program ini dimulai dengan mendefinisikan sebuah array berisi angka yang akan diproses.** Dalam program ini, data angka berasal dari beberapa daerah, di mana masing-masing daerah memiliki sejumlah bilangan. Fungsi sorting kemudian dipanggil untuk memisahkan angka ganjil dan genap dalam setiap daerah. Angka ganjil disimpan dalam array `allGanjil` dan angka genap dalam array `allGenap`.
Selanjutnya, setiap array akan diurutkan secara terpisah: angka ganjil diurutkan secara menaik menggunakan fungsi `selectionSortAscending`, sementara angka genap diurutkan secara menurun menggunakan fungsi `selectionSortDescending`. Setelah kedua array diurutkan, program mencetak hasilnya ke layar dengan format ganjil terlebih dahulu diikuti oleh genap, masing-masing pada satu baris per daerah.
Hasil akhirnya adalah tampilan data setiap daerah yang telah terurut sesuai dengan aturan yang telah ditentukan, yaitu angka ganjil dari kecil ke besar dan angka genap dari besar ke kecil, dan seluruh hasil ditampilkan setelah semua input selesai diproses.

___
#### **nomor 3**
>Kompetisi pemrograman yang baru saja berlalu diikuti oleh 17 tim dari berbagai perguruan tinggi ternama. Dalam kompetisi tersebut, setiap tim berlomba untuk menyelesaikan sebanyak mungkin problem yang diberikan. Dari 13 problem yang diberikan, ada satu problem yang menarik. Problem tersebut mudah dipahami, hampir semua tim mencoba untuk menyelesaikannya, tetapi hanya 3 tim yang berhasil. Apa sih problemnya? "Median adalah nilai tengah dari suatu koleksi data yang sudah terurut. Jika jumlah data genap, maka nilai median adalah rerata dari kedua nilai tengahnya. Pada problem ini, semua data merupakan bilangan bulat positif, dan karenanya rerata nilai tengah dibulatkan ke bawah." Buatlah program median yang mencetak nilai median terhadap seluruh data yang sudah terbaca, jika data yang dibaca saat itu adalah 0
>
>Masukan : berbentuk rangkaian bilangan bulat. Masukan tidak akan berisi lebih dari 1000000 data, tidak termasuk bilangan 0. Data 0 merupakan tanda bahwa median harus dicetak, tidak termasuk data yang dicari mediannya. Data masukan diakhiri dengan bilangan bulat -5313.
>
>Keluaran : adalah median yang diminta, satu data per baris.

```go
package main

import (
	"fmt"
)

// Selection Sort function
func selectionSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	}
}

// Fungsi untuk mendapatkan median
func getMedian(arr []int) int {
	selectionSort(arr) // urutkan data
	n := len(arr)
	if n%2 == 1 {
		return arr[n/2]
	}
	return (arr[n/2-1] + arr[n/2]) / 2 // dibulatkan ke bawah
}

func main() {
	var input int
	data := []int{}

	for {
		fmt.Scan(&input)
		if input == -5313 {
			break
		} else if input == 0 {
			// saat menemukan 0, hitung median dan cetak
			if len(data) > 0 {
				// buat salinan agar data asli tidak terganggu oleh pengurutan
				temp := make([]int, len(data))
				copy(temp, data)
				median := getMedian(temp)
				fmt.Println(median)
			}
		} else {
			data = append(data, input)
		}
	}
}
```
Output:

>![](output/Uss3.PNG)

Penjelasan:
**Program ini dimulai dengan mendefinisikan sebuah array berisi angka yang akan diproses.** Data angka dimasukkan satu per satu melalui input, dan disimpan dalam array `data`. Fungsi sorting kemudian dipanggil untuk mengurutkan array ketika ditemukan input bernilai `0`, yang menandakan bahwa saat itu median harus dihitung.
Angka `-5313` berfungsi sebagai sinyal untuk menghentikan proses input. Setiap kali angka `0` dimasukkan, program akan menyalin isi array ke array sementara, kemudian mengurutkannya menggunakan algoritma _Selection Sort_ agar data asli tidak berubah. Setelah array terurut, fungsi `getMedian` akan menghitung nilai tengah dari data tersebut. Jika jumlah elemen ganjil, maka median adalah elemen tengah. Jika genap, median diambil sebagai rata-rata dua nilai tengah dan dibulatkan ke bawah.
Hasil akhirnya adalah program yang secara dinamis menerima input angka, menghitung dan menampilkan median setiap kali ditemukan angka `0`, dan akan berhenti ketika pengguna memasukkan `-5313`.
___
# B. Insertion Short
#### **nomor 1**
>Buatlah sebuah program yang digunakan untuk membaca data integer seperti contoh yang diberikan di bawah ini, kemudian diurutkan (menggunakan metoda insertion sort), dan memeriksa apakah data yang terurut berjarak sama terhadap data sebelumnya.
>
>Masukan : terdiri dari sekumpulan bilangan bulat yang diakhiri oleh bilangan negatif. Hanya bilangan non negatif saja yang disimpan ke dalam array.
>
>Keluaran : terdiri dari dua baris. Baris pertama adalah isi dari array setelah dilakukan pengurutan, sedangkan baris kedua adalah status jarak setiap bilangan yang ada di dalam array. "Data berjarak x" atau "data berjarak tidak tetap".

```go
package main

import (
	"fmt"
)

// Fungsi insertion sort
func insertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}

// Fungsi untuk memeriksa apakah array berjarak tetap
func checkSameDistance(arr []int) (bool, int) {
	if len(arr) < 2 {
		return true, 0
	}
	distance := arr[1] - arr[0]
	for i := 2; i < len(arr); i++ {
		if arr[i]-arr[i-1] != distance {
			return false, 0
		}
	}
	return true, distance
}

func main() {
	var input int
	data := []int{}

	// Input sampai bilangan negatif
	for {
		fmt.Scan(&input)
		if input < 0 {
			break
		}
		data = append(data, input)
	}

	// Urutkan data
	insertionSort(data)

	// Tampilkan hasil sorting
	for _, v := range data {
		fmt.Print(v, " ")
	}
	fmt.Println()

	// Cek apakah data berjarak tetap
	sameDistance, distance := checkSameDistance(data)
	if sameDistance {
		fmt.Printf("Data berjarak %d\n", distance)
	} else {
		fmt.Println("Data berjarak tidak tetap")
	}
}
```
Output:

>![](output/Uis1.PNG)

Penjelasan:
**Program ini dimulai dengan mendefinisikan sebuah array berisi angka yang akan diproses.** Pengguna memasukkan data bilangan bulat satu per satu, dan proses input akan berhenti jika sebuah bilangan negatif dimasukkan. Fungsi sorting kemudian dipanggil untuk mengurutkan array menggunakan algoritma _Insertion Sort_, yang bekerja dengan menyisipkan elemen ke posisi yang tepat dalam bagian array yang sudah terurut.
Setelah proses pengurutan selesai, program mencetak data yang telah terurut tersebut. Selanjutnya, program memeriksa apakah angka-angka dalam array memiliki selisih (jarak) yang tetap antar elemen, dengan memeriksa apakah perbedaan antara elemen-elemen bertetangga selalu sama. Jika iya, maka akan ditampilkan pesan bahwa data berjarak tetap beserta nilai jaraknya. Jika tidak, akan ditampilkan pesan bahwa data tidak berjarak tetap.
Hasil akhirnya adalah tampilan data yang sudah terurut serta informasi apakah data tersebut memiliki jarak tetap atau tidak setelah semua input selesai diproses.

---
#### **nomor 2**
>Sebuah program perpustakaan digunakan untuk mengelola data buku di dalam suatu perpustakaan. Misalnya terdefinisi struct dan array seperti berikut ini:

```
const nMax : integer = 7919
type Buku = <
 id, judul, penulis, penerbit : string
 eksemplar, tahun, rating : integer >
type DaftarBuku = array [ 1..nMax] of Buku
Pustaka : DaftarBuku
nPustaka: integer
```
>Masukan : terdiri dari beberapa baris. Baris pertama adalah bilangan bulat N yang menyatakan banyaknya data buku yang ada di dalam perpustakaan. N baris berikutnya, masing-masingnya adalah data buku sesuai dengan atribut atau field pada struct. Baris terakhir adalah bilangan bulat yang menyatakan rating buku yang akan dicari.
>
>Keluaran : terdiri dari beberapa baris. Baris pertama adalah data buku terfavorit, baris kedua adalah lima judul buku dengan rating tertinggi, selanjutnya baris terakhir adalah data buku yang dicari sesuai rating yang diberikan pada masukan baris terakhir.

```go
package main

import (
	"fmt"
)

const nMax = 7919

type Buku struct {
	ID       string
	Judul    string
	Penulis  string
	Penerbit string
	Eks      int
	Tahun    int
	Rating   int
}

type DaftarBuku []Buku

func DaftarkanBuku(n int) DaftarBuku {
	pustaka := make(DaftarBuku, n)
	for i := 0; i < n; i++ {
		fmt.Printf("Masukkan data buku ke-%d:\n", i+1)
		fmt.Print("ID: ")
		fmt.Scan(&pustaka[i].ID)
		fmt.Print("Judul: ")
		fmt.Scan(&pustaka[i].Judul)
		fmt.Print("Penulis: ")
		fmt.Scan(&pustaka[i].Penulis)
		fmt.Print("Penerbit: ")
		fmt.Scan(&pustaka[i].Penerbit)
		fmt.Print("Jumlah Eksemplar: ")
		fmt.Scan(&pustaka[i].Eks)
		fmt.Print("Tahun Terbit: ")
		fmt.Scan(&pustaka[i].Tahun)
		fmt.Print("Rating: ")
		fmt.Scan(&pustaka[i].Rating)
	}
	return pustaka
}

func CetakTerfavorit(pustaka DaftarBuku) {
	maxRating := -1
	for _, buku := range pustaka {
		if buku.Rating > maxRating {
			maxRating = buku.Rating
		}
	}
	fmt.Println("\nBuku Terfavorit:")
	for _, buku := range pustaka {
		if buku.Rating == maxRating {
			fmt.Printf("- %s, %s, %s, %d\n", buku.Judul, buku.Penulis, buku.Penerbit, buku.Tahun)
		}
	}
}

func UrutBuku(pustaka DaftarBuku) {
	for i := 1; i < len(pustaka); i++ {
		key := pustaka[i]
		j := i - 1
		for j >= 0 && pustaka[j].Rating < key.Rating {
			pustaka[j+1] = pustaka[j]
			j--
		}
		pustaka[j+1] = key
	}
}

func Cetak5Terbaru(pustaka DaftarBuku) {
	fmt.Println("\n5 Buku dengan Rating Tertinggi:")
	count := 5
	if len(pustaka) < 5 {
		count = len(pustaka)
	}
	for i := 0; i < count; i++ {
		b := pustaka[i]
		fmt.Printf("%d. %s\n", i+1, b.Judul)
	}
}

func CariBuku(pustaka DaftarBuku, r int) {
	left, right := 0, len(pustaka)-1
	for left <= right {
		mid := (left + right) / 2
		if pustaka[mid].Rating == r {
			b := pustaka[mid]
			fmt.Printf("\nBuku dengan rating %d ditemukan:\n", r)
			fmt.Printf("- %s, %s, %s, %d eks, %d, rating: %d\n", b.Judul, b.Penulis, b.Penerbit, b.Eks, b.Tahun, b.Rating)
			return
		} else if pustaka[mid].Rating < r {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	fmt.Println("\nTidak ada buku dengan rating seperti itu.")
}

func main() {
	var n int
	fmt.Print("Masukkan jumlah data buku: ")
	fmt.Scan(&n)

	pustaka := DaftarkanBuku(n)
	CetakTerfavorit(pustaka)
	UrutBuku(pustaka)
	Cetak5Terbaru(pustaka)

	var rating int
	fmt.Print("\nMasukkan rating buku yang ingin dicari: ")
	fmt.Scan(&rating)
	CariBuku(pustaka, rating)
}
```
Output:

>![](output/Uis2.PNG)

Penjelasan:
Program ini digunakan untuk mengelola daftar buku dengan informasi seperti ID, judul, penulis, penerbit, eksemplar, tahun terbit, dan rating. Fungsi `DaftarkanBuku` digunakan untuk memasukkan data buku ke dalam array `DaftarBuku`, sementara `UrutBuku` mengurutkan buku berdasarkan rating tertinggi menggunakan algoritma insertion sort. Fungsi `CetakTerfavorit` menampilkan buku dengan rating tertinggi, sedangkan `Cetak5Terbaru` mencetak lima buku dengan rating tertinggi atau kurang jika jumlah buku lebih sedikit. Fungsi `CariBuku` mencari buku dengan rating tertentu dan menampilkan semua buku yang memiliki rating tersebut. Program ini memungkinkan pengguna untuk mengelola dan mencari buku berdasarkan rating serta menampilkan buku-buku terfavorit dan terbaru sesuai dengan rating tertinggi.