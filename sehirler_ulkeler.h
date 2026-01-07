#ifndef sehirler_ulkeler_h
#define sehirler_ulkeler_h


struct Oyuncu {         // Oyuncu bilgilerini tutan güncellenmiş yapı
    char isim[50];
    int sehir_oyun;
    int sehir_puan;
    int ulke_oyun;
    int ulke_puan;
};




struct Duzen {          //Seçilen bir şehrin/ülkenin yapısını belirler.
    char teknik_ad[50]; //Tahmin ile karşılaştırılacak olan addır.
    char gorsel_ad[50]; //Oyun sonunda kullanıcıya gösterilecek olan Türkçe harflerden oluşan addır.
    char bolge[50];     //Şehrin bölgesini, Ülkenin kıtasını içerir. İpucu için kullanılır.
};

// 81 şehri plaka sırasına göre tutan yapılar dizisi
const struct Duzen Sehirler[81] = {
	
    // Teknik Ad       | Görsel Ad        | Bölge Adı

    {"ADANA", "Adana", "Akdeniz"},
    {"ADIYAMAN", "Adıyaman", "Güneydoğu Anadolu"},
    {"AFYONKARAHİSAR", "Afyonkarahisar", "Ege"},
    {"AĞRI", "Ağrı", "Doğu Anadolu"},
    {"AMASYA", "Amasya", "Karadeniz"},
    {"ANKARA", "Ankara", "İç Anadolu"},
    {"ANTALYA", "Antalya", "Akdeniz"},
    {"ARTVİN", "Artvin", "Karadeniz"},
    {"AYDIN", "Aydın", "Ege"},
    {"BALIKESİR", "Balıkesir", "Marmara"},
    {"BİLECİK", "Bilecik", "Marmara"},
    {"BİNGÖL", "Bingöl", "Doğu Anadolu"},
    {"BİTLİS", "Bitlis", "Doğu Anadolu"},
    {"BOLU", "Bolu", "Karadeniz"},
    {"BURDUR", "Burdur", "Akdeniz"},
    {"BURSA", "Bursa", "Marmara"},
    {"ÇANAKKALE", "Çanakkale", "Marmara"},
    {"ÇANKIRI", "Çankırı", "İç Anadolu"},
    {"ÇORUM", "Çorum", "Karadeniz"},
    {"DENİZLİ", "Denizli", "Ege"},
    {"DİYARBAKIR", "Diyarbakır", "Güneydoğu Anadolu"},
    {"EDİRNE", "Edirne", "Marmara"},
    {"ELAZIĞ", "Elazığ", "Doğu Anadolu"},
    {"ERZİNCAN", "Erzincan", "Doğu Anadolu"},
    {"ERZURUM", "Erzurum", "Doğu Anadolu"},
    {"ESKİŞEHİR", "Eskişehir", "İç Anadolu"},
    {"GAZİANTEP", "Gaziantep", "Güneydoğu Anadolu"},
    {"GİRESUN", "Giresun", "Karadeniz"},
    {"GÜMÜŞHANE", "Gümüşhane", "Karadeniz"},
    {"HAKKARİ", "Hakkâri", "Doğu Anadolu"},
    {"HATAY", "Hatay", "Akdeniz"},
    {"ISPARTA", "Isparta", "Akdeniz"},
    {"MERSİN", "Mersin", "Akdeniz"},
    {"İSTANBUL", "İstanbul", "Marmara"},
    {"İZMİR", "İzmir", "Ege"},
    {"KARS", "Kars", "Doğu Anadolu"},
    {"KASTAMONU", "Kastamonu", "Karadeniz"},
    {"KAYSERİ", "Kayseri", "İç Anadolu"},
    {"KIRKLARELİ", "Kırklareli", "Marmara"},
    {"KIRŞEHİR", "Kırşehir", "İç Anadolu"},
    {"KOCAELİ", "Kocaeli", "Marmara"},
    {"KONYA", "Konya", "İç Anadolu"},
    {"KÜTAHYA", "Kütahya", "Ege"},
    {"MALATYA", "Malatya", "Doğu Anadolu"},
    {"MANİSA", "Manisa", "Ege"},
    {"KAHRAMANMARAŞ", "Kahramanmaraş", "Akdeniz"},
    {"MARDİN", "Mardin", "Güneydoğu Anadolu"},
    {"MUĞLA", "Muğla", "Ege"},
    {"MUŞ", "Muş", "Doğu Anadolu"},
    {"NEVŞEHİR", "Nevşehir", "İç Anadolu"},
    {"NİĞDE", "Niğde", "İç Anadolu"},
    {"ORDU", "Ordu", "Karadeniz"},
    {"RİZE", "Rize", "Karadeniz"},
    {"SAKARYA", "Sakarya", "Marmara"},
    {"SAMSUN", "Samsun", "Karadeniz"},
    {"SİİRT", "Siirt", "Güneydoğu Anadolu"},
    {"SİNOP", "Sinop", "Karadeniz"},
    {"SİVAS", "Sivas", "İç Anadolu"},
    {"TEKİRDAĞ", "Tekirdağ", "Marmara"},
    {"TOKAT", "Tokat", "Karadeniz"},
    {"TRABZON", "Trabzon", "Karadeniz"},
    {"TUNCELİ", "Tunceli", "Doğu Anadolu"},
    {"ŞANLIURFA", "Şanlıurfa", "Güneydoğu Anadolu"},
    {"UŞAK", "Uşak", "Ege"},
    {"VAN", "Van", "Doğu Anadolu"},
    {"YOZGAT", "Yozgat", "İç Anadolu"},
    {"ZONGULDAK", "Zonguldak", "Karadeniz"},
    {"AKSARAY", "Aksaray", "İç Anadolu"},
    {"BAYBURT", "Bayburt", "Karadeniz"},
    {"KARAMAN", "Karaman", "İç Anadolu"},
    {"KIRIKKALE", "Kırıkkale", "İç Anadolu"},
    {"BATMAN", "Batman", "Güneydoğu Anadolu"},
    {"ŞIRNAK", "Şırnak", "Güneydoğu Anadolu"},
    {"BARTIN", "Bartın", "Karadeniz"},
    {"ARDAHAN", "Ardahan", "Doğu Anadolu"},
    {"IĞDIR", "Iğdır", "Doğu Anadolu"},
    {"YALOVA", "Yalova", "Marmara"},
    {"KARABÜK", "Karabük", "Karadeniz"},
    {"KİLİS", "Kilis", "Güneydoğu Anadolu"},
    {"OSMANİYE", "Osmaniye", "Akdeniz"},
    {"DÜZCE", "Düzce", "Karadeniz"}
};





















// 196 ülkeyi kıta ve harf sırasına göre tutan yapılar dizisi
const struct Duzen Ulkeler[196] = {
    // Teknik Ad           | Görsel Ad             | Kıta/Bölge
    // -------------------------------------------------------------------------
    
    // --- AVRUPA (44 Ülke) ---
    {"ALMANYA", "Almanya", "Avrupa"},
    {"ARNAVUTLUK", "Arnavutluk", "Avrupa"},
    {"ANDORRA", "Andorra", "Avrupa"},
    {"AVUSTURYA", "Avusturya", "Avrupa"},
    {"BELÇİKA", "Belçika", "Avrupa"},
    {"BELARUS", "Belarus", "Avrupa"},
    {"BOSNA HERSEK", "Bosna Hersek", "Avrupa"},
    {"BULGARİSTAN", "Bulgaristan", "Avrupa"},
    {"ÇEK CUMHURİYETİ", "Çek Cumhuriyeti", "Avrupa"},
    {"DANİMARKA", "Danimarka", "Avrupa"},
    {"ESTONYA", "Estonya", "Avrupa"},
    {"FİNLANDİYA", "Finlandiya", "Avrupa"},
    {"FRANSA", "Fransa", "Avrupa"},
    {"HIRVATİSTAN", "Hırvatistan", "Avrupa"},
    {"HOLLANDA", "Hollanda", "Avrupa"},
    {"İNGİLTERE", "İngiltere", "Avrupa"},
    {"İRLANDA", "İrlanda", "Avrupa"},
    {"İSPANYA", "İspanya", "Avrupa"},
    {"İSVEÇ", "İsveç", "Avrupa"},
    {"İSVİÇRE", "İsviçre", "Avrupa"},
    {"İTALYA", "İtalya", "Avrupa"},
    {"İZLANDA", "İzlanda", "Avrupa"},
    {"KARADAĞ", "Karadağ", "Avrupa"},
    {"KIBRIS RUM KESİMİ", "Kıbrıs Rum Kesimi", "Avrupa"},
    {"KOSOVA", "Kosova", "Avrupa"},
    {"LETONYA", "Letonya", "Avrupa"},
    {"LİHTENŞTAYN", "Lihtenştayn", "Avrupa"},
    {"LİTVANYA", "Litvanya", "Avrupa"},
    {"LÜKSEMBURG", "Lüksemburg", "Avrupa"},
    {"MACARİSTAN", "Macaristan", "Avrupa"},
    {"MAKEDONYA", "Makedonya", "Avrupa"},
    {"MALTA", "Malta", "Avrupa"},
    {"MOLDOVA", "Moldova", "Avrupa"},
    {"MONAKO", "Monako", "Avrupa"},
    {"NORVEÇ", "Norveç", "Avrupa"},
    {"POLONYA", "Polonya", "Avrupa"},
    {"PORTEKİZ", "Portekiz", "Avrupa"},
    {"ROMANYA", "Romanya", "Avrupa"},
    {"SAN MARİNO", "San Marino", "Avrupa"},
    {"SIRBİSTAN", "Sırbistan", "Avrupa"},
    {"SLOVAKYA", "Slovakya", "Avrupa"},
    {"SLOVENYA", "Slovenya", "Avrupa"},
    {"UKRAYNA", "Ukrayna", "Avrupa"},
    {"VATİKAN", "Vatikan", "Avrupa"},
    {"YUNANİSTAN", "Yunanistan", "Avrupa"},
    
    // --- ASYA (48 Ülke) ---
    {"AFGANİSTAN", "Afganistan", "Asya"},
    {"BAHREYN", "Bahreyn", "Asya"},
    {"BANGLADEŞ", "Bangladeş", "Asya"},
    {"BHUTAN", "Bhutan", "Asya"},
    {"BİRLEŞİK ARAP EMİRLİKLERİ", "Birleşik Arap Emirlikleri", "Asya"},
    {"BRUNEİ", "Brunei", "Asya"},
    {"ÇİN", "Çin", "Asya"},
    {"DOĞU TİMOR", "Doğu Timor", "Asya"},
    {"ENDONEZYA", "Endonezya", "Asya"},
    {"FİLİPİNLER", "Filipinler", "Asya"},
    {"FİLİSTİN", "Filistin", "Asya"},
    {"GÜNEY KORE", "Güney Kore", "Asya"},
    {"GÜRCİSTAN", "Gürcistan", "Avrupa ve Asya"}, // Çift kıta
    {"HİNDİSTAN", "Hindistan", "Asya"},
    {"IRAK", "Irak", "Asya"},
    {"İRAN", "İran", "Asya"},
    {"İSRAİL", "İsrail", "Asya"},
    {"JAPONYA", "Japonya", "Asya"},
    {"KAMBOÇYA", "Kamboçya", "Asya"},
    {"KATAR", "Katar", "Asya"},
    {"KAZAKİSTAN", "Kazakistan", "Avrupa ve Asya"}, // Çift kıta
    {"KIRGIZİSTAN", "Kırgızistan", "Asya"},
    {"KUZEY KORE", "Kuzey Kore", "Asya"},
    {"KUVEYT", "Kuveyt", "Asya"},
    {"LAOS", "Laos", "Asya"},
    {"LÜBNAN", "Lübnan", "Asya"},
    {"MALDİVLER", "Maldivler", "Asya"},
    {"MALEZYA", "Malezya", "Asya"},
    {"MOĞOLİSTAN", "Moğolistan", "Asya"},
    {"MYANMAR", "Myanmar", "Asya"},
    {"NEPAL", "Nepal", "Asya"},
    {"ÖZBEKİSTAN", "Özbekistan", "Asya"},
    {"PAKİSTAN", "Pakistan", "Asya"},
    {"RUSYA", "Rusya", "Avrupa ve Asya"}, // Çift kıta
    {"SİNGAPUR", "Singapur", "Asya"},
    {"SRİ LANKA", "Sri Lanka", "Asya"},
    {"SURİYE", "Suriye", "Asya"},
    {"TACİKİSTAN", "Tacikistan", "Asya"},
    {"TAYLAND", "Tayland", "Asya"},
    {"TAYVAN", "Tayvan", "Asya"},
    {"TURKMENİSTAN", "Türkmenistan", "Asya"},
    {"TÜRKİYE", "Türkiye", "Avrupa ve Asya"}, // Çift kıta
    {"UMMAN", "Umman", "Asya"},
    {"ÜRDÜN", "Ürdün", "Asya"},
    {"VİETNAM", "Vietnam", "Asya"},
    {"YEMEN", "Yemen", "Asya"},
    {"ERMENİSTAN", "Ermenistan", "Asya"},
    {"AZERBAYCAN", "Azerbaycan", "Avrupa ve Asya"}, // Çift kıta

    // --- AFRIKA (54 Ülke) ---
    {"CEZAYİR", "Cezayir", "Afrika"},
    {"MISIR", "Mısır", "Afrika ve Asya"}, // Çift kıta
    {"GüNEY AFRiKA", "Güney Afrika", "Afrika"},
    {"NİJERYA", "Nijerya", "Afrika"},
    {"FAS", "Fas", "Afrika"},
    {"KENYA", "Kenya", "Afrika"},
    {"ETİYOPYA", "Etiyopya", "Afrika"},
    {"TANZANYA", "Tanzanya", "Afrika"},
    {"UGANDA", "Uganda", "Afrika"},
    {"SUDAN", "Sudan", "Afrika"},
    {"DEMOKRATİK KONGO CUMHURİYETİ", "Demokratik Kongo Cumhuriyeti", "Afrika"},
    {"RUANDA", "Ruanda", "Afrika"},
    {"BURUNDİ", "Burundi", "Afrika"},
    {"SOMALİ", "Somali", "Afrika"},
    {"LİBYA", "Libya", "Afrika"},
    {"TUNUS", "Tunus", "Afrika"},
    {"CEYHUN", "Ceyhun", "Afrika"},
    {"ZİMBABVE", "Zimbabve", "Afrika"},
    {"ZAMBİYA", "Zambiya", "Afrika"},
    {"MADAGASKAR", "Madagaskar", "Afrika"},
    {"NAMİBYA", "Namibya", "Afrika"},
    {"BOTSVANA", "Botsvana", "Afrika"},
    {"ANGOLA", "Angola", "Afrika"},
    {"GABON", "Gabon", "Afrika"},
    {"KAMERUN", "Kamerun", "Afrika"},
    {"NİJER", "Nijer", "Afrika"},
    {"MALİ", "Mali", "Afrika"},
    {"MORİTANYA", "Moritanya", "Afrika"},
    {"SENEGAL", "Senegal", "Afrika"},
    {"GİNE", "Gine", "Afrika"},
    {"GANA", "Gana", "Afrika"},
    {"FİLDİŞİ SAHİLİ", "Fildişi Sahili", "Afrika"},
    {"BURKİNA FASO", "Burkina Faso", "Afrika"},
    {"BENİN", "Benin", "Afrika"},
    {"TOGO", "Togo", "Afrika"},
    {"SİERRA LEONE", "Sierra Leone", "Afrika"},
    {"LİBERYA", "Liberya", "Afrika"},
    {"KOMORLAR", "Komorlar", "Afrika"},
    {"CAP VERDE", "Cap Verde", "Afrika"},
    {"EKVATOR GİNESİ", "Ekvator Ginesi", "Afrika"},
    {"ERİTRE", "Eritre", "Afrika"},
    {"CİBUTİ", "Cibuti", "Afrika"},
    {"LESOTHO", "Lesotho", "Afrika"},
    {"MALAWİ", "Malawi", "Afrika"},
    {"MAURİTİUS", "Mauritius", "Afrika"},
    {"MOZAMBİK", "Mozambik", "Afrika"},
    {"SEYŞELLER", "Seyşeller", "Afrika"},
    {"SWAZİLAND", "Svaziland", "Afrika"},
    {"SAO TOME VE PRİNCİPE", "Sao Tome ve Principe", "Afrika"},
    {"GÜNEY SUDAN", "Güney Sudan", "Afrika"},
    {"ORTA AFRİKA CUMHURİYETİ", "Orta Afrika Cumhuriyeti", "Afrika"},
    {"KONGO CUMHURİYETİ", "Kongo Cumhuriyeti", "Afrika"},
    {"BURKİNA FASO", "Burkina Faso", "Afrika"},
    {"ÇAD", "Çad", "Afrika"},

    // --- KUZEY AMERIKA (23 Ülke) ---
    {"AMERİKA BİRLEŞİK DEVLETLERİ", "Amerika Birleşik Devletleri", "Kuzey Amerika"},
    {"KANADA", "Kanada", "Kuzey Amerika"},
    {"MEKSİKA", "Meksika", "Kuzey Amerika"},
    {"PANAMA", "Panama", "Kuzey ve Güney Amerika"}, // Çift kıta
    {"BAHAMALAR", "Bahamalar", "Kuzey Amerika"},
    {"BARBADOS", "Barbados", "Kuzey Amerika"},
    {"BELİZE", "Belize", "Kuzey Amerika"},
    {"KOSTA RİKA", "Kosta Rika", "Kuzey Amerika"},
    {"KÜBA", "Küba", "Kuzey Amerika"},
    {"DOMİNİK CUMHURİYETİ", "Dominik Cumhuriyeti", "Kuzey Amerika"},
    {"EL SALVADOR", "El Salvador", "Kuzey Amerika"},
    {"GRENADA", "Grenada", "Kuzey Amerika"},
    {"GUATEMALA", "Guatemala", "Kuzey Amerika"},
    {"HAİTİ", "Haiti", "Kuzey Amerika"},
    {"HONDURAS", "Honduras", "Kuzey Amerika"},
    {"JAMAİKA", "Jamaika", "Kuzey Amerika"},
    {"NİKARAGUA", "Nikaragua", "Kuzey Amerika"},
    {"SAİNT KİTTS VE NEVİS", "Saint Kitts ve Nevis", "Kuzey Amerika"},
    {"SAİNT LUCİA", "Saint Lucia", "Kuzey Amerika"},
    {"SAİNT VİNCENT VE GRENADİNLER", "Saint Vincent ve Grenadinler", "Kuzey Amerika"},
    {"TRİNİDAD VE TOBAGO", "Trinidad ve Tobago", "Kuzey Amerika"},
    {"ANTİGUA VE BARBUDA", "Antigua ve Barbuda", "Kuzey Amerika"},
    {"DOMİNİKA", "Dominika", "Kuzey Amerika"},
    
    // --- GÜNEY AMERIKA (12 Ülke) ---
    {"ARJANTİN", "Arjantin", "Güney Amerika"},
    {"BREZİLYA", "Brezilya", "Güney Amerika"},
    {"BOLİVYA", "Bolivya", "Güney Amerika"},
    {"ŞİLİ", "Şili", "Güney Amerika"},
    {"KOLOMBİYA", "Kolombiya", "Güney Amerika"},
    {"EKVADOR", "Ekvador", "Güney Amerika"},
    {"GUYANA", "Guyana", "Güney Amerika"},
    {"PARAGUAY", "Paraguay", "Güney Amerika"},
    {"PERU", "Peru", "Güney Amerika"},
    {"SURİNAM", "Surinam", "Güney Amerika"},
    {"URUGUAY", "Uruguay", "Güney Amerika"},
    {"VENEZUELA", "Venezuela", "Güney Amerika"},

    // --- Okyanusya (14 Ülke) ---
    {"AVUSTRALYA", "Avustralya", "Okyanusya"},
    {"YENİ ZELANDA", "Yeni Zelanda", "Okyanusya"},
    {"FİJİ", "Fiji", "Okyanusya"},
    {"PAPUA YENİ GİNE", "Papua Yeni Gine", "Okyanusya"},
    {"SAMOA", "Samoa", "Okyanusya"},
    {"TONGA", "Tonga", "Okyanusya"},
    {"TUVALU", "Tuvalu", "Okyanusya"},
    {"VANUATU", "Vanuatu", "Okyanusya"},
    {"KİRİBATİ", "Kiribati", "Okyanusya"},
    {"MARSHALL ADALARI", "Marshall Adaları", "Okyanusya"},
    {"MİKRONESYA", "Mikronezya", "Okyanusya"},
    {"NAURU", "Nauru", "Okyanusya"},
    {"PALAU", "Palau", "Okyanusya"},
    {"SOLOMON ADALARI", "Solomon Adaları", "Okyanusya"}
};

#endif
