from django.shortcuts import render, redirect
from .models import About, Project, Contact, Edu, Other
from .forms import FormContact

def index(request):
    about = About.objects.get(id=1)
    projects = Project.objects.all()
    edu = Edu.objects.all()
    other = Other.objects.all()
    context = {
        'about' : about,
        'projects' : projects,
        'form' : FormContact(),
        'edu' : edu,
        'other' : other,
    }
    return render(request, 'index.html', context)

def send_contact(request):
    if request.method == 'POST':
        form = FormContact(request.POST)
        if form.is_valid():
             form.save()
        else:
            print(form.errors)  # Tambahkan ini
            return redirect('/#contact')  # Redirect setelah form berhasil disubmit
    else:
        form = FormContact()  # Jika bukan POST, buat form baru
    return redirect('/#contact')  # Jika form tidak valid atau request bukan POST

    
