from django.db import models


class About(models.Model): 
    nama = models.CharField(max_length=100)
    pekerjaan = models.CharField(max_length=100)
    foto = models.ImageField(upload_to = 'foto')
    tentang = models.TextField()
    def __str__(self):
        return self.nama
    
class Project(models.Model):
    nama = models.CharField(max_length = 30)
    foto = models.ImageField(upload_to = 'foto')
    keterangan = models.TextField()
    tanggal = models.TimeField(auto_now=True)
    def __str__(self):
        return self.nama

class Contact(models.Model):
    nama = models.CharField(max_length = 30)
    email = models.EmailField(max_length = 30 )
    pesan = models.TextField()
    tanggal = models.TimeField(auto_now=True)
    def __str__(self):
        return self.nama

class Edu(models.Model):
    nama = models.CharField(max_length = 50)
    foto = models.ImageField(upload_to = 'foto')
    keterangan = models.TextField()
    tanggal = models.TimeField(auto_now=True)
    def __str__(self):
        return self.nama

class Other(models.Model):
    nama = models.CharField(max_length = 50)
    foto = models.ImageField(upload_to = 'foto')
    keterangan = models.TextField()
    tanggal = models.TimeField(auto_now=True)
    def __str__(self):
        return self.nama
