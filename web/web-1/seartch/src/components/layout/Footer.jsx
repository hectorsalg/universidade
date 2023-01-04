import styles from "./Footer.module.css";

export default function Footer(){
    const year = new Date().getFullYear()

    return (
        <footer className={styles.containerFooter}>
            <div><span>Sobre nós</span> <span>Designer</span></div>
            <div>&copy; {year} Seartch</div>
        </footer>
    );
}