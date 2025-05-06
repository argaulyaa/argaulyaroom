/*!
* Start Bootstrap - Freelancer v7.0.7 (https://startbootstrap.com/theme/freelancer)
* Copyright 2013-2023 Start Bootstrap
* Licensed under MIT (https://github.com/StartBootstrap/startbootstrap-freelancer/blob/master/LICENSE)
*/
//
// Scripts
// 

window.addEventListener('DOMContentLoaded', event => {

    // Navbar shrink function
    var navbarShrink = function () {
        const navbarCollapsible = document.body.querySelector('#mainNav');
        if (!navbarCollapsible) {
            return;
        }
        if (window.scrollY === 0) {
            navbarCollapsible.classList.remove('navbar-shrink')
        } else {
            navbarCollapsible.classList.add('navbar-shrink')
        }

    };

    // Shrink the navbar 
    navbarShrink();

    // Shrink the navbar when page is scrolled
    document.addEventListener('scroll', navbarShrink);

    // Activate Bootstrap scrollspy on the main nav element
    const mainNav = document.body.querySelector('#mainNav');
    if (mainNav) {
        new bootstrap.ScrollSpy(document.body, {
            target: '#mainNav',
            rootMargin: '0px 0px -40%',
        });
    };

    // Collapse responsive navbar when toggler is visible
    const navbarToggler = document.body.querySelector('.navbar-toggler');
    const responsiveNavItems = [].slice.call(
        document.querySelectorAll('#navbarResponsive .nav-link')
    );
    responsiveNavItems.map(function (responsiveNavItem) {
        responsiveNavItem.addEventListener('click', () => {
            if (window.getComputedStyle(navbarToggler).display !== 'none') {
                navbarToggler.click();
            }
        });
    });

});
    const navbar = document.getElementById('mainNav');
    let lastScrollY = window.scrollY;
    let currentTranslateY = 0;
    let maxTranslate = -100; // maksimal navbar "naik" ke atas (misalnya -100px)

    function updateNavbar() {
        const currentScrollY = window.scrollY;
        const delta = currentScrollY - lastScrollY;

        // Scroll down
        if (delta > 0) {
            currentTranslateY = Math.max(maxTranslate, currentTranslateY - delta);
        } 
        // Scroll up
        else {
            currentTranslateY = Math.min(0, currentTranslateY - delta);
        }

        navbar.style.transform = `translateY(${currentTranslateY}px)`;
        lastScrollY = currentScrollY;
        requestAnimationFrame(updateNavbar);
    }

    requestAnimationFrame(updateNavbar);

    window.addEventListener('DOMContentLoaded', () => {
        const alert = document.querySelector('.alert-success');
        if (alert) {
            document.getElementById('contact')?.scrollIntoView({ behavior: 'smooth' });
        }
    });
