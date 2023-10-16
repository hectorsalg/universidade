import styles from "./Header.module.css";

import Logo from "../../assets/logo.png"

import { BsList, BsSearch } from "react-icons/bs"

export default function Header(){
    return (
        <header className={styles.containerHeader}>
            <span>
                <BsList />
            </span>
            <span><img src={Logo} alt="logo" className={styles.image} /></span>
            <div className={styles.containerHeaderDiv}>
                <button className={styles.btnLogin}>Conecte-se</button>
                <span>
                    <BsSearch /> 
                </span>
            </div>
        </header>
    );
}