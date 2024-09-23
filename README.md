# TFF E-Bilet Simulator Projesi

Bu proje, Türkiye Futbol Federasyonu'na (TFF) sunulan e-bilet sisteminin bir simülasyonunu gerçekleştirir. Kullanıcılar, çeşitli verileri (isim, TC kimlik numarası, yaş, takım, müsabaka bilgisi ve resim) JSON formatında bir API'ye gönderir. Proje, e-bilet sürecini simüle ederek, biletleme sisteminin doğru çalıştığını test etmeyi amaçlar.

## Proje Aşamaları

TFF E-Bilet Simulator projesi üç aşamada geliştirilmiştir:

### 1. Aşama: Temel Kullanıcı Veri Girişi
İlk aşamada, kullanıcılar isim, TC kimlik numarası, yaş, takım ve resim gibi bilgileri girerek bu verileri **JSON** formatında bir **API** adresine gönderebilirler. Bu aşama, manuel veri girişine dayanır ve temel bir e-bilet simülasyonunu içerir.

### 2. Aşama: Rastgele Veri Üretimi ve Gönderimi
İkinci aşamada, sistem rastgele veri üretme kapasitesi kazandı. Kullanıcıların verilerini elle girmek yerine, simülatör rastgele oluşturduğu kullanıcı bilgilerini API’ye otomatik olarak gönderebilir. Bu özellik, yüksek hacimli testler için kullanışlıdır.

### 3. Aşama: Çoklu Ekran ve Şablon Yönetimi
Son aşamada, proje aşağıdaki ekranlarla genişletildi:
- **Kullanıcı Giriş Ekranı**: Kullanıcılar, var olan şablonları seçerek veya yeni veriler girerek giriş yapabilir.
- **Şablon Ekranı**: Kullanıcılar, farklı veri tiplerini (ör. `int`, `string`, `image`) içeren kendi şablonlarını oluşturabilir. Şablonlar kaydedilebilir ve tekrar kullanılabilir.
- **Ayarlar Ekranı**: Kullanıcılar, veri göndermek için kullanılan **API** sunucu adresini ayarlayabilir.
- **Logger Ekranı**: Sistem tarafından yapılan tüm işlemler burada görüntülenir.

## Özellikler

- **JSON Formatında Veri Gönderimi**: E-Bilet sistemi için gerekli olan tüm kullanıcı verileri JSON formatına dönüştürülerek API'ye gönderilir.
- **Rastgele Veri Üretimi**: Test senaryoları için simülatör, rastgele kullanıcı bilgileri oluşturarak bu bilgileri API'ye iletir.
- **Şablon Yönetimi**: Kullanıcılar, çeşitli şablonlar oluşturarak belirli veri türlerini otomatik olarak tekrar kullanabilirler.
- **Ayarlar Yönetimi**: API sunucu adresi ayarlanabilir ve her veri gönderiminde bu adres kullanılır.
- **Logger Ekranı**: Tüm işlemler (veri gönderimi, API bağlantısı, hata durumları vb.) kaydedilir ve görüntülenir.

## Kullanım

### Gereksinimler
Bu projeyi kullanmadan önce aşağıdaki bileşenlerin yüklü olduğundan emin olun:
- Python 3.x
- Qt ile ilgili kütüphaneler
- Bir RESTful API ile iletişim için internet bağlantısı
- C++

### Kurulum

Projeyi klonlayarak başlayın:
```bash
git clone https://github.com/ahmetarifozden/TFF
cd TFF

### Katkıda Bulunanlar

- **Proje Sahibi**: [Netas]
