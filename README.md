🌍 Şehir ve Ülke Tahmin Oyunu (C Programlama)

Bu proje, C dili kullanılarak geliştirilmiş, interaktif bir kelime tahmin oyunudur. Kullanıcılar Türkiye'nin 81 ilini veya dünya üzerindeki 190'dan fazla ülkeyi belirli bir puan ve hak sistemi dahilinde tahmin etmeye çalışır.

👤 Geliştirici Bilgileri

Okul/Bölüm: Marmara Üniversitesi TBMYO/Bilgisayar Programcılığı 

Ad Soyad: Hüseyin Dil

Öğrenci Numarası: 360125058

Proje Türü: Algoritma ve Programlama Dersi Projesi

🚀 Özellikler

İki Farklı Mod: Şehir Tahmini (81 İl) ve Ülke Tahmini (190+ Ülke).

Gelişmiş İpucu Sistemi: - Rastgele harf alma (10 Puan).

Kelimenin ilk harfini görme (15 Puan).

Bölge/Kıta bilgisini öğrenme (20 Puan).

Dinamik Puanlama: 150 başlangıç puanı ile her yanlış tahminde veya ipucunda azalan puan sistemi.

Türkçe Karakter Desteği: locale.h kütüphanesi ile terminal üzerinde doğru karakter gösterimi.

Akıllı Girdi Yönetimi: Kullanıcı girişleri otomatik olarak büyük harfe çevrilir ve Türkçe karakter hassasiyeti (I/İ ayrımı gibi) yönetilir.

🛠 Kullanılan Teknolojiler

Dil: C

Kütüphaneler: - stdio.h, stdlib.h, time.h (Rastgele sayı üretimi için)

string.h, ctype.h (Metin işleme için)

locale.h (Yerelleştirme ve karakter desteği için)

📖 Nasıl Çalıştırılır?

Bilgisayarınızda bir C derleyicisinin (GCC, Clang, Visual Studio vb.) kurulu olduğundan emin olun.

main.c ve sehirler_ulkeler.h dosyalarını aynı klasöre indirin.

Derleyicinizde main.c dosyasını açın ve derleyip çalıştırın.

Terminal komutu: gcc main.c -o tahmin_oyunu

Çalıştırma: ./tahmin_oyunu

📝 Notlar

Bu proje, modüler programlama prensiplerine uygun olarak hazırlanmıştır. Veri yapıları (struct) header dosyasında (.h), oyun mantığı ise ana kaynak dosyada (.c) tutulmuştur.
